/**
 * @file SolveVisitor.h
 * @author Keerthi Vardhan
 *
 * Visitor class to add numbers to right spots
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SOLVEVISITOR_H
#define ACTIONSUDOKU_SUDOKULIB_SOLVEVISITOR_H

#include "ItemVisitor.h"

class PlayableArea;
class NumberD;

/**
 * Class to add numbers to board
 */
class SolveVisitor : public ItemVisitor
{
private:
    /// The point to be added to
    wxPoint mPoint;

    /// The playable area
    PlayableArea* mPlayableArea;

    /// Value to be added
    int mVal;

    /// If number is added
    bool mAdded = false;

public:
    SolveVisitor(wxPoint point, int val, PlayableArea* playableArea);

    void VisitDigit(NumberD* digit) override;

};

#endif //ACTIONSUDOKU_SUDOKULIB_SOLVEVISITOR_H
