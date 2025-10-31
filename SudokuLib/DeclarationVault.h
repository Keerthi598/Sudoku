/**
 * @file DeclarationVault.h
 * @author Mate Narh
 *
 * Declaration class for Vault
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_DECLARATIONVAULT_H
#define ACTIONSUDOKU_SUDOKULIB_DECLARATIONVAULT_H

#include "DeclarationContainer.h"

/**
 * Declaration class for Vault
 */
class DeclarationVault : public DeclarationContainer
{
private:
    /// Image filename for lever
    std::wstring mLeverImage;

    /// Image filename for bulb
    std::wstring mBulbImage;

    std::vector<int> mLeverDimensions; ///< The width and height of the lever
    std::vector<int> mBulbDimensions;  ///< The width and height of the bulb

public:
    DeclarationVault(int width, int height, std::wstring image, std::wstring front,
                     std::wstring leverImage, std::vector<int> leverDimensions,
                     std::wstring bulbImage,  std::vector<int> bulbDimensions);

    /**
     * Get the lever image filename
     * @return the lever image filename
     */
    std::wstring GetLeverImage() override { return mLeverImage; };

    /**
     * Get the bulb image filename
     * @return the bulb image filename
     */
    std::wstring GetBulbImage() override { return mBulbImage; };

    /**
     * Get the lever width
     * @return the width of the lever in pixels
     */
    std::vector<int> GetLeverDimensions() override { return mLeverDimensions; }

    /**
     * Get the width and height of the bulb
     * @return vector of the width and height of the bulb in pixels
     */
    std::vector<int> GetBulbDimensions() override { return mBulbDimensions; }
};

#endif //ACTIONSUDOKU_SUDOKULIB_DECLARATIONVAULT_H
