/**
 * @file PlayableArea.cpp
 * @author Kyle
 */

#include "pch.h"
#include "PlayableArea.h"

#include "Game.h"
#include "BoardNumber.h"
#include "FindGivens.h"
#include "GameState.h"
#include "SolveVisitor.h"

/// Number of columns and rows on main Sudoku Board
const int NumberOfBox = 9;

/**
* Constructor
 * @param game
*/
PlayableArea::PlayableArea(Game *game)
{
    mGame = game;
}

/**
 * Load and store solution
 * @param node
 */
void PlayableArea::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"col", L"0").ToDouble(&mColumn);
    node->GetAttribute(L"row", L"0").ToDouble(&mRow);

    auto x = node->GetChildren();
    auto y = x->GetContent().ToStdWstring();

    CreateSolution(y);
}

/**
 * Convert solution wstring to vector
 * @param solution
 */
void PlayableArea::CreateSolution(std::wstring solution)
{
    std::wstringstream ss(solution);
    int num;

    // Place each number into vector using wstringstream
    while (ss >> num)
    {
        mSolution.push_back(num);
    }

    SetLoc();
}


/**
 * Checks if point is on the main playing field
 * @param x
 * @param y
 * @return bool
 */
bool PlayableArea::HitTest(double x, double y)
{
    auto relativeX = x - mX;
    auto relativeY = y - mY;

    if (relativeX < 0 || relativeX > mWidth)
        return false;

    if (relativeY < 0 || relativeY > mHeight)
        return false;

    return true;
}


/**
 * Get the middle point of a specific box
 * @param x
 * @param y
 * @return Middle point of the box on board
 */
wxPoint PlayableArea::GetBoardCoords(double x, double y)
{
    auto relativeX = x - mX;
    auto relativeY = y - mY;

    int col = int (relativeX / mTileWidth);
    int row = int (relativeY / mTileHeight);

    double c = (col + 0.5)*mTileWidth; // +0.5 to get the middle of the box to avoid collisions
    double r = (row + 0.5)*mTileWidth;

    return wxPoint(c + mX, r + mY);
}

/**
 * Convert on board points to col, row
 * @param x
 * @param y
 * @return
 */
wxPoint PlayableArea::GetOnBoardLoc(double x, double y)
{
    auto relativeX = x - mX;
    auto relativeY = y - mY;

    int col = int (relativeX / mTileWidth);
    int row = int (relativeY / mTileHeight);

    return wxPoint(col, row);
}

/**
 * Sets the location and details of this board
 */
void PlayableArea::SetLoc()
{
    mHeight = mTileWidth * NumberOfBox;
    mWidth = mTileWidth * NumberOfBox;


    mX = mColumn * mTileWidth;
    mY = mRow * mTileHeight;
}

/**
 * Checks if something exists in the given point on board
 * @param point
 * @return
 */
bool PlayableArea::CheckBoard(wxPoint point)
{
    BoardNumber visitor(point);

    mGame->Accept(&visitor);

    if (visitor.GetNumber() == nullptr)
        return true;

    return false;
}

/**
 * Check if board is solved
 * @return true is solution is correct
 */
bool PlayableArea::CheckSolution()
{
    GameState visitor(this);

    mGame->Accept(&visitor);

    auto state = visitor.GetCurrState();

    if (mSolution == state)
        return true;

    return false;
}

/**
 * Calc the initial number of numbers on board
 */
void PlayableArea::CalcOnBoard()
{
    FindGivens visitor;

    mGame->Accept(&visitor);

    mCurrentlyOnBoard = visitor.GetGivens();
}

/**
 * Solve the board
 */
void PlayableArea::Solve()
{
    double currX = mTileWidth/2;
    double currY = mTileHeight/2;

    int col, row;

    wxPoint posInit(mX + currX, mY + currY);

    wxPoint currPos;


    for(int i = 0; i < (NumberOfBox*NumberOfBox); i++)
    {
        col = i % NumberOfBox;
        row = int(i / NumberOfBox);

        currPos.x = posInit.x + (col * mTileWidth);
        currPos.y = posInit.y + (row * mTileHeight);

        if (!CheckBoard(currPos))
            continue;

        SolveVisitor visitor(currPos, mSolution[i], this);
        mGame->Accept(&visitor);

    }
}

/**
 * Return the position at which the number can be placed
 * @param pos mid point of the box
 * @return bottom left point of box
 */
wxPoint PlayableArea::GetTargetCords(wxPoint pos)
{
    return wxPoint(pos.x - (0.5*mTileWidth), pos.y + (0.5*mTileHeight));
}
