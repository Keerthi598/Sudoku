/**
 * @file DeclarationVault.cpp
 * @author Mate Narh
 *
 * Defines the functionality of the Vault Declaration class
 */

#include "pch.h"
#include "DeclarationVault.h"

/**
 * Constructor
 * @param width Vault width in pixels
 * @param height Vault height in pixels
 * @param image Image filename for vault back display
 * @param front Image filename for Vault front display
 * @param leverImage Image filename for lever
 * @param leverDimensions Vector of lever width and height in pixels
 * @param bulbImage Image filename for bulb indicator
 * @param bulbDimensions Vector of bulb width and height in pixels
 */
DeclarationVault::DeclarationVault(int width, int height, std::wstring image, std::wstring front,
                                   std::wstring leverImage, std::vector<int> leverDimensions,
                                   std::wstring bulbImage, std::vector<int> bulbDimensions) :
                                   DeclarationContainer(width, height, image, front)
{
    mLeverImage = leverImage;
    mLeverDimensions = leverDimensions;

    mBulbImage = bulbImage;
    mBulbDimensions = bulbDimensions;
}
