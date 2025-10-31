/**
 * @file PlayableArea.h
 * @author Kyle
 *
 * The sudoku puzzle area
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_PLAYABLEAREA_H
#define ACTIONSUDOKU_SUDOKULIB_PLAYABLEAREA_H

#include "vector"
#include "sstream"

class Game;

/**
 * Contains the sudoku board
 */
class PlayableArea
{
private:

    ///Column of top left square of sudoku
    double mColumn;

    ///Row of top left square of sudoku
    double mRow;

    ///Vector of sudoku solution
    std::vector<int> mSolution;

    /// The game it is a solution to
    Game* mGame;

    double mTileHeight;  ///< Tile Height
    double mTileWidth;   ///< Tile Width

    double mHeight;      ///< Height of the board
    double mWidth;       ///< Width of the board

    double mX;           ///< X co ords of the board
    double mY;           ///< Y co ords of the board

    void CreateSolution(std::wstring solution);

    /// Total number of items on board at the moment
    int mCurrentlyOnBoard = 0;

protected:
    /**
     * Set the position for the board for testing
     * @param x
     * @param y
     */
    void SetPos(double x, double y) {mColumn = x; mRow = y;}

    void SetLoc();


public:
    PlayableArea(Game* game);

    /// Default constructor (disabled)
    PlayableArea() = delete;

    /// Copy constructor (disabled)
    PlayableArea(const PlayableArea &) = delete;

    void XmlLoad(wxXmlNode* node);

    /**
     * Set the dimensions of each box
     * @param x Width
     * @param y Height
     */
    void SetTileDim(double x, double y) {mTileWidth = x; mTileHeight = y;}

    bool HitTest(double x, double y);

    wxPoint GetBoardCoords(double x, double y);

    bool CheckBoard(wxPoint point);

    void CalcOnBoard();

    bool CheckSolution();

    wxPoint GetOnBoardLoc(double x, double y);

    /**
     * Add number to board
     */
    void AddToBoard() { mCurrentlyOnBoard++; }

    /**
     * Remove number from board
     */
    void Remove() { mCurrentlyOnBoard--; }

    /**
     * Get the number of items on board
     * @return
     */
    int OnBoard() {return mCurrentlyOnBoard;}

    wxPoint GetTargetCords(wxPoint pos);

    void Solve();
};

#endif //ACTIONSUDOKU_SUDOKULIB_PLAYABLEAREA_H
