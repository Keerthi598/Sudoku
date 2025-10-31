/**
 * @file DeclarationNum.h
 * @author Keerthi Vardhan
 *
 * The Declaration class for a number
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_DECLARATIONNUM_H
#define ACTIONSUDOKU_SUDOKULIB_DECLARATIONNUM_H

#include "Declaration.h"


/**
 * The declaration class for a number
 */
class DeclarationNum : public Declaration
{
private:

    ///The value of this object
    int mValue;

public:
    DeclarationNum(int width, int height, std::wstring image, int value);

    /**
     * Get the value of this object
     * @return
     */
    int GetValue() override { return mValue; }

};

#endif //ACTIONSUDOKU_SUDOKULIB_DECLARATIONNUM_H
