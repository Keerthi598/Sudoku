/**
 * @file GameState.h
 * @author Keerthi Vardhan
 *
 * Visitor to create a game state
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_GAMESTATE_H
#define ACTIONSUDOKU_SUDOKULIB_GAMESTATE_H

#include "ItemVisitor.h"
#include <vector>

class PlayableArea;

/**
 * Visitor that creates the current board of the game
 */
class GameState : public ItemVisitor
{
private:
    /// The playable area
    PlayableArea* mPlayableArea;

    /// The vector representing the current state of the game
    std::vector<int> mState;

public:
    GameState(PlayableArea*);

    void VisitGiven(NumberG* given) override;

    /**
     * Return the current state
     * @return 1D vector of the current state of the game
     */
    std::vector<int> GetCurrState() {return mState;}

};

#endif //ACTIONSUDOKU_SUDOKULIB_GAMESTATE_H
