/**
 * @file Item.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

using namespace std;

/**
 * Item Constructor
 * @param game
 */
Item::Item(Game *game)
{
    mGame = game;
}

/**
 * Item Destructor
 */
Item::~Item()
{
}


/**
 * Draw the item
 * @param graphics
 */
void Item::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    if (mItemImage != nullptr)
    {
        // FIX: We need to fix how graphics is being referenced in this scope
        graphics->DrawBitmap(*mItemBitmap,mX, mY, mWidth, mHeight);
    }
}



/**
 * Set the image of this item
 * @param image the image file name for this item
 */
void Item::SetImage(const wstring image)
{
    if (!image.empty())
    {
        wstring imageName = mGame->GetImgDir() + L"/" + image;
        mItemImage = make_unique<wxImage>(imageName, wxBITMAP_TYPE_ANY);
        mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    }
    else
    {
        mItemImage.release();
        mItemBitmap.release();
    }
}


/**
 * Load the item from the xml
 * @param dec The declaration for this item
 */
void Item::XmlLoad(shared_ptr<Declaration> dec)
{
    mWidth = dec->GetWidth();
    mHeight = dec->GetHeight();
    SetImage(dec->GetImage());
}

/**
 * Checks if the given co ords lie on the item
 * @param x x co ords
 * @param y y co ords
 * @return bool
 */
bool Item::HitTest(double x, double y)
{
    if(mItemImage == nullptr)
        return false;

    auto relativeX = x - mX;
    auto relativeY = y - mY;

    if (relativeX < 0 || relativeX > mWidth)
        return false;

    if (relativeY < 0 || relativeY > mHeight)
        return false;

    return true;
}
