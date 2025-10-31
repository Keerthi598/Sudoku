/**
 * @file DeclarationContainer.h
 * @author Keerthi Vardhan
 *
 * Declaration for container
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_DECLARATIONCONTAINER_H
#define ACTIONSUDOKU_SUDOKULIB_DECLARATIONCONTAINER_H

#include "Declaration.h"


/**
 * Class for container declaration
 */
class DeclarationContainer : public Declaration
{
private:
    ///Image file for the front of the container
    std::wstring mFront;

public:
    DeclarationContainer(int width, int height, std::wstring image, std::wstring front);

    /**
     * Get the image of the front
     * @return front image
     */
    std::wstring GetFront() override { return mFront; }

};

#endif //ACTIONSUDOKU_SUDOKULIB_DECLARATIONCONTAINER_H
