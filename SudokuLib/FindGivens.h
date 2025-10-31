/**
 * @file FindGivens.h
 * @author Keerthi Vardhan
 *
 * Find the number of givens at the start of the game
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_FINDGIVENS_H
#define ACTIONSUDOKU_SUDOKULIB_FINDGIVENS_H

#include "ItemVisitor.h"

/**
 * Visitor to find the number of givens in the game
 */
class FindGivens : public ItemVisitor
{
private:

    /// Number of givens
    int mGiven = 0;

public:
    FindGivens();

    void VisitGiven(NumberG* given) override;

    /**
     * Get the number of givens initially
     * @return
     */
    int GetGivens() {return mGiven;}

};

#endif //ACTIONSUDOKU_SUDOKULIB_FINDGIVENS_H
