/**
 * @file DeclarationXray.h
 * @author Keerthi Vardhan
 *
 * Declaration of an xray
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_DECLARATIONXRAY_H
#define ACTIONSUDOKU_SUDOKULIB_DECLARATIONXRAY_H

#include "Declaration.h"

/**
 * Declaration of an xray
 */
class DeclarationXray : public Declaration
{
private:
    int mCapacity;  ///< Max capacity of xray

public:
    DeclarationXray(int width, int height, std::wstring image, int capacity);

    /**
     * Get the capacity
     * @return capacity
     */
    int GetCap() override { return mCapacity; }

};

#endif //ACTIONSUDOKU_SUDOKULIB_DECLARATIONXRAY_H
