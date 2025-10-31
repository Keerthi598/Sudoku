/**
 * @file Game.h
 * @author Keerthi Vardhan
 *
 * Class that implements and manages the game
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_GAME_H
#define ACTIONSUDOKU_SUDOKULIB_GAME_H

#include <memory>
#include <vector>
#include "Item.h"
#include "Sparty.h"
#include "Xray.h"
#include "LoadLevel.h"
#include "PlayableArea.h"

#include "ItemVisitor.h"

#include "ScoreBoard.h"
#include "ScreenText.h"


/**
 * Class that implements and manages the game
 */
class Game
{
private:

    ///All the items in the game
    std::vector<std::shared_ptr<Item> > mItems;

    double mXOffset = 0;  ///< The x offset
    double mYOffset = 0;  ///< The y offset
    double mScale;        ///< The scale

    int mTileWidth = 0;   ///< The tile width of the current level
    int mTileHeight = 0;  ///< The tile height of the current level
    int mWidth = 0;       ///< The number of columns
    int mHeight = 0;      ///< The number of rows

    std::wstring mDir = L"images"; ///< The image directory

    Sparty* mSparty;    ///< The sparty item

    std::shared_ptr<PlayableArea> mPlayableArea;   ///< The playable area

    std::unique_ptr<ScoreBoard> mScore;  ///< The scoreboard

    int mItemsLoaded = 0; ///< Number of items loaded for test purposes

    /// Class to display screen texts
    ScreenText mScreenText;

    /// Current level
    int mCurrLevel;

    bool mAdvanceLevel;

protected:
    /**
     * Get Sparty Target
     * Purely for testing
     * @return
     */
    wxPoint GetSpartyTarget(){return mSparty->GetT();}

    /**
     * True if sparty is moving
     * Purely for testing
     * @return
     */
    bool SpartyMoving(){return mSparty->IsMoving();}


public:
    Game();

    /**
     * Destructor
     */
    virtual ~Game() = default;

    /**
     * Get the image directory
     * @return directory
     */
    std::wstring GetImgDir() { return mDir; }

    /**
     * Sets the sparty item
     * @param sparty
     */
    void SetSparty(Sparty* sparty) { mSparty = sparty; }

    void SetPlayableArea(std::shared_ptr<PlayableArea> playableArea);

    void Eat();

    void HeadButt();

    void OnLeftDown(double x, double y);

    void Move(double x, double y);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Update(double elapsed);

    void Load(const wxString &filename, int level);

    void Add(std::shared_ptr<Item> item, double column, double row);

    void Clear();

    int ItemsLoaded();

    void Regurgitate(int x);

    void Accept(ItemVisitor* visitor);

    void CheckSol();

    void Solve();

    bool Advance();

    int CurrLevel() {return mCurrLevel;};
};

#endif //ACTIONSUDOKU_SUDOKULIB_GAME_H
