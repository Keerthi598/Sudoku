/**
 * @file SpecialContainer.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "SpecialContainer.h"
#include "Game.h"
#include "ItemVisitor.h"

#include <memory>

using namespace std;

/**
 * Container
 * @param game
 */
SpecialContainer::SpecialContainer(Game *game) : Container(game)
{
}

/**
 * Load from Xml
 * @param dec Contains the information
 */
void SpecialContainer::XmlLoad(std::shared_ptr<Declaration> dec)
{
    Item::XmlLoad(dec);

    auto fileName = Item::GetGame()->GetImgDir() + L"/" + dec->GetFront();

    mFrontImage = make_unique<wxImage>(fileName, wxBITMAP_TYPE_ANY);
    mFrontBitMap = make_unique<wxBitmap>(*mFrontImage);
}


/**
 * Draw container and items if not broken
 * @param graphics
 */
void SpecialContainer::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);

    if(mIsBroken)
        return;

    for(auto item : mContains)
        item->ContainerDraw(graphics);

    graphics->DrawBitmap(*mFrontBitMap, Item::GetX(), Item::GetY(), Item::GetWidth(), Item::GetHeight());
}


/**
 * Accept visitor
 * @param visitor
 */
void SpecialContainer::Accept(ItemVisitor *visitor)
{
    Container::Accept(visitor);
    visitor->VisitSpecialContainer(this);
}
