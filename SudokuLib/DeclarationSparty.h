/**
 * @file DeclarationSparty.h
 * @author Keerthi Vardhan
 *
 * The Declaration of sparty
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_DECLARATIONSPARTY_H
#define ACTIONSUDOKU_SUDOKULIB_DECLARATIONSPARTY_H

#include "Declaration.h"

#include <vector>
#include <string>


/**
 * The declaration class for sparty
 */
class DeclarationSparty : public Declaration
{
private:
    /// Store the target points
    std::vector<int> mTarget;

    /// Store the pivot values
    std::vector<double> mPivot;

    /// Store the images
    std::vector<std::wstring> mImages;

public:
    DeclarationSparty(int width, int height, std::vector<int> target, std::vector<double> pivot, std::vector<std::wstring> images);

    /**
     * Return the target points
     * @return
     */
    std::vector<int> GetTarget() override { return mTarget; }

    /**
     * Return the pivot points
     * @return
     */
    std::vector<double> GetPivot() override { return mPivot; }

    /**
     * Return the images
     * @return
     */
    std::vector<std::wstring> GetImages() override { return mImages; }

};

#endif //ACTIONSUDOKU_SUDOKULIB_DECLARATIONSPARTY_H
