/**
 * @file Vault.cpp
 * @author Mate Narh
 *
 * Defines Vault funcitonality
 */

#include "pch.h"
#include "Vault.h"
#include "Game.h"
#include "ItemVisitor.h"

#include <memory>

using namespace std;

/**
 * Constructor
 * @param game The game this Vault belongs to
 */
Vault::Vault(Game *game) : SpecialContainer(game)
{

}

/**
 * Load Vault features from Vault's XML declaration object
 * @param dec Contains the initializer information for the Vault
 */
void Vault::XmlLoad(std::shared_ptr<Declaration> dec)
{
    SpecialContainer::XmlLoad(dec);

    auto leverFileName = Item::GetGame()->GetImgDir() + L"/" + dec->GetLeverImage();
    auto bulbFileName = Item::GetGame()->GetImgDir() + L"/" + dec->GetBulbImage();

    mLeverImage = make_unique<wxImage>(leverFileName, wxBITMAP_TYPE_ANY);
    mLeverBitmap = make_unique<wxBitmap>(*mLeverImage);

    mBulbImage = make_unique<wxImage>(bulbFileName, wxBITMAP_TYPE_ANY);
    mBulbBitmap = make_unique<wxBitmap>(*mBulbBitmap);

    auto leverDimensions = dec->GetLeverDimensions();
    auto bulbDimensions = dec->GetBulbDimensions();

    mLeverWidth = leverDimensions[0];
    mLeverHeight = leverDimensions[1];

    mBulbWidth = bulbDimensions[0];
    mBulbHeight = bulbDimensions[1];
}

