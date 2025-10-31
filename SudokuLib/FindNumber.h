/**
 * @file FindNumber.h
 * @author Keerthi Vardhan
 *
 * Finds if a number exists at the target location for eating
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_FINDNUMBER_H
#define ACTIONSUDOKU_SUDOKULIB_FINDNUMBER_H

#include "ItemVisitor.h"

/**
 * Visitor to find if a number exists at a given location
 */
class FindNumber : public ItemVisitor
{
private:
    /// Point to be checked
    wxPoint mTarget;

    /// Digit if eatable
    NumberD* mDigit = nullptr;

public:
    FindNumber(wxPoint target);

    void VisitDigit(NumberD* digit) override;

    /**
     * Return number if found at the specific co ords
     * @return
     */
    NumberD* GetNumber() { return mDigit; }

};

#endif //ACTIONSUDOKU_SUDOKULIB_FINDNUMBER_H
