/**
 * @file BoardNumber.h
 * @author Keerthi Vardhan
 *
 * Visitor to find a number in main board
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_BOARDNUMBER_H
#define ACTIONSUDOKU_SUDOKULIB_BOARDNUMBER_H

#include "ItemVisitor.h"

class NumberG;

/**
 * Visitor to find number on the main sudoku board
 */
class BoardNumber : public ItemVisitor
{
private:
    /// Number if found in a box
    NumberG* mNumber = nullptr;

    /// Point to be be searched
    wxPoint mPoint;

public:
    BoardNumber(wxPoint point);

    void VisitGiven(NumberG* given);

    /**
     * Return number if found on co ords
     * @return number pointer
     */
    NumberG* GetNumber() { return mNumber; }

};

#endif //ACTIONSUDOKU_SUDOKULIB_BOARDNUMBER_H
