/**
 * @file Vault.h
 * @author Mate Narh
 *
 * Base class for Vault, the level 3 special feature
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_VAULT_H
#define ACTIONSUDOKU_SUDOKULIB_VAULT_H

#include "SpecialContainer.h"

/**
 * Base class for Vault, the level 3 special feature
 */
class Vault : public SpecialContainer
{
private:
    std::unique_ptr<wxImage> mLeverImage;   ///< Image of lever
    std::unique_ptr<wxBitmap> mLeverBitmap; ///< Bitmap of lever

    std::unique_ptr<wxImage> mBulbImage;    ///< Image of bulb
    std::unique_ptr<wxBitmap> mBulbBitmap;  ///< Bitmap of bulb

    int mLeverWidth;  ///< Width of lever
    int mLeverHeight; ///< Height of lever
    int mBulbWidth;   ///< Width of bulb
    int mBulbHeight;  ///< Height of bulb


public:
    Vault(Game *game);

    void XmlLoad(std::shared_ptr<Declaration> dec) override;

};

#endif //ACTIONSUDOKU_SUDOKULIB_VAULT_H
