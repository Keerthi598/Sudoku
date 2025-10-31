/**
 * @file GameState.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "GameState.h"

#include "PlayableArea.h"
#include "NumberG.h"

using namespace std;

/// Number of columns and rows on main Sudoku Board
const int NumberOfBox = 9;

/**
 * Constructor
 * @param playableArea
 */
GameState::GameState(PlayableArea* playableArea) : ItemVisitor()
{
    mPlayableArea = playableArea;
    mState = vector<int>(NumberOfBox*NumberOfBox, NumberOfBox);
}

/**
 * Create current game state
 * @param given
 */
void GameState::VisitGiven(NumberG *given)
{
    auto curr = mPlayableArea->GetOnBoardLoc(given->GetX(), given->GetY());

    auto loc = (curr.y * NumberOfBox) + curr.x;

    mState[loc] = given->GetValue();
}
