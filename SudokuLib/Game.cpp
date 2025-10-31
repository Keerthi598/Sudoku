/**
 * @file Game.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "Game.h"
#include "NumberD.h"
#include "NumberG.h"
#include <wx/graphics.h>

#include "Item.h"
#include "Xray.h"
#include "Background.h"

#include "FindNumber.h"
#include "XrayManip.h"

using namespace std;

/**
 * Constructor
 */
Game::Game()
{
}


/**
 * Draw
 * @param graphics
 * @param width
 * @param height
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    int pixelWidth = mTileWidth*mWidth;
    int pixelHeight = mTileHeight*(mHeight);

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(pixelWidth);
    auto scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);


    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

    if(mScore != nullptr)
        mScore->Draw(graphics);


    mScreenText.OnDraw(graphics, pixelWidth, pixelHeight);

    graphics->PopState();


}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    mScreenText.Update(elapsed);

    if (mScreenText.Pause())
        return;

    if (mScreenText.AdvanceLevel())
    {
        // Code to go the next level
        mAdvanceLevel = true;
        return;
    }

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    if(mScore != nullptr)
        mScore->Update(elapsed);
}

/**
 * Load a level
 * @param filename The xml file for the level
 */
void Game::Load(const wxString &filename, int level)
{
    wxXmlDocument xmlDoc;

    mItemsLoaded = 0;

    mScore = make_unique<ScoreBoard>();

    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Wrong");
        return;
    }

    mCurrLevel = level;

    auto root = xmlDoc.GetRoot();

    root->GetAttribute(L"width").ToInt(&mWidth);
    root->GetAttribute(L"height").ToInt(&mHeight);
    root->GetAttribute(L"tilewidth").ToInt(&mTileWidth);
    root->GetAttribute(L"tileheight").ToInt(&mTileHeight);

    LoadLevel(&xmlDoc, this);

    mScore->Start();

    mPlayableArea->CalcOnBoard();

}

/**
 * Add an item to this game
 * @param item The item
 * @param column The column location
 * @param row The row location
 */
void Game::Add(std::shared_ptr<Item> item, double column, double row)
{
    mItems.push_back(item);
    auto temp = row + 1;

    auto g = temp * mTileHeight;
    item->SetLocation(column * mTileWidth,  temp * mTileHeight);
    mItemsLoaded += 1;
}

/**
 * Eat the number
 */
void Game::Eat()
{
    mSparty->Eat(); //Animation

    auto target = mSparty->GetTarget();

    //Visitor to find digit at co ordinates

    FindNumber visitorNum(target);

    Accept(&visitorNum);

    NumberD* num = visitorNum.GetNumber();

    if (num == nullptr)
        return;

    // Check if xray is full

    XrayManip visitorXray;
    Accept(&visitorXray);

    if (visitorXray.IsFull())
    {
        // Code for if xray is full
        return;
    }

    // Xray is not full

    bool inBoard = num->OnBoard();

    if(inBoard)
    {
        num->SwitchBoard();
        mPlayableArea->Remove();
    }


    visitorXray.AddToXray(num);

}

/**
 * Head butt
 */
void Game::HeadButt()
{
    mSparty->HeadButt();
}

/**
 * Computer virtual co ords for the co ordinates
 * @param x
 * @param y
 */
void Game::OnLeftDown(double x, double y)
{
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

    if (oX <= 0 || oX >= (mTileWidth * mWidth))
        return;

    if (oY <= 0 || oY >= (mTileHeight * mHeight))
        return;

    auto z = true;

    Move(oX, oY);
}

/**
 * Move sparty to the point
 * @param x
 * @param y
 */
void Game::Move(double x, double y)
{
    // Move the sparty
    mSparty->Move(x, y);
}

/**
 * Clear game
 */
void Game::Clear()
{

    mItems.clear();

    mTileWidth = 0;
    mTileHeight = 0;
    mWidth = 0;
    mHeight = 0;

    mSparty = nullptr;
    mPlayableArea = nullptr;

    if(mScore != nullptr)
        mScore->Stop();

    mItemsLoaded = 0;
}

/**
 * Find number of items loaded in game
 * @return
 */
int Game::ItemsLoaded()
{
    return mItemsLoaded;
}

/**
 * Regurtitate a number from gut if exists
 * @param x Number to be regurtitated
 */
void Game::Regurgitate(int x)
{
    XrayManip visitorXray;
    Accept(&visitorXray);

    auto number = visitorXray.GetNumber(x);

    if(number == nullptr)
        return;

    auto point = mSparty->GetTarget();

    bool onBoard = mPlayableArea->HitTest(point.x, point.y);

    if (!onBoard)  // Not in playing area
    {
        number->SetContainer(nullptr);

        // Slightly adjust the new location
        number->SetLocation(point.x - (mTileWidth / 2), point.y + (mTileHeight / 2));

        visitorXray.RemoveFromXray(number);

        mSparty->Eat();

        return;
    }

    // In Playing area

    point = mPlayableArea->GetBoardCoords(point.x, point.y);

    bool canBePlaced = mPlayableArea->CheckBoard(point);

    if (!canBePlaced)
    {
        // Code to display that board has stuff in it
        return;
    }

    number->SetContainer(nullptr);

    number->SwitchBoard();

    mPlayableArea->AddToBoard();

    //Change to account for board co ords being middle of the board
    auto newPoint = mPlayableArea->GetTargetCords(point);

    number->SetLocation(newPoint.x, newPoint.y);

    visitorXray.RemoveFromXray(number);

    //Animation
    mSparty->Eat();

    // Check if solved
    CheckSol();
}

/**
 * Check if game is solved
 */
void Game::CheckSol()
{
    if(mPlayableArea->OnBoard() < 81)   // Not all numbers on board
        return;

    // All digits on board
    // Check if correct

    bool isCorrect = mPlayableArea->CheckSolution();

    if (!isCorrect)
    {
        //Display incorrect message
        //mInCorrect = true;
        //mTime = 0.001;
        mScreenText.Incorrect();
        return;
    }

    //Display correct message
    //mCorrect = true;
    //mTime = 0.001;
    mScreenText.IsCorrect();
}

/**
 * Sets the playing Area
 * @param playableArea
 */
void Game::SetPlayableArea(std::shared_ptr<PlayableArea> playableArea)
{
    mPlayableArea = playableArea;
    mPlayableArea->SetTileDim(mTileWidth, mTileHeight);
}


/**
 * Solve the current level
 */
void Game::Solve()
{
    mPlayableArea->Solve();
    // Check if solved
    CheckSol();
}

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void Game::Accept(ItemVisitor *visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}



bool Game::Advance()
{
    if (!mAdvanceLevel)
        return false;

    mAdvanceLevel = false;

    return true;
}


