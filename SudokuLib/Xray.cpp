/**
 * @file Xray.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "Xray.h"
#include "ItemVisitor.h"
#include "NumberD.h"

/// Value to be scaled down to for digits in Xray
const double XrayScale = 0.6;

/**
 * Constructor
 * @param game
 */
Xray::Xray(Game *game) : Container(game)
{
    std::random_device rd;
    mRandom.seed(rd());
}


/**
 * Load item from the Xml
 * @param dec
 */
void Xray::XmlLoad(std::shared_ptr<Declaration> dec)
{
    Item::XmlLoad(dec);
    mCapacity = dec->GetCap();

    mDistributionX.param(std::uniform_real_distribution<>::param_type(0, Item::GetWidth()));
    mDistributionY.param(std::uniform_real_distribution<>::param_type(0, Item::GetHeight()));
}


/**
 * Accept visitor
 * @param visitor
 */
void Xray::Accept(ItemVisitor *visitor)
{
    Container::Accept(visitor);
    visitor->VisitXray(this);
}

/**
 * Draw container and items
 * @param graphics
 */
void Xray::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);

    graphics->PushState();

    graphics->Translate(Item::GetX(), Item::GetY());

    graphics->Scale(XrayScale, XrayScale);


    for(auto item : mItems)
        item->ContainerDraw(graphics);

    graphics->PopState();
}

/**
 * Add item to xray
 * @param number
 */
void Xray::AddItem(NumberD* number)
{
    mContains++;

    number->SetContainer(this);
    mItems.push_back(number);

    auto x = mDistributionX(mRandom);
    auto y = mDistributionY(mRandom);
    y = y + number->GetHeight();

    number->SetLocation(x, y);
}

/**
 * Get the digit corresponding to the value
 * @param x Number to be found
 * @return NumberD
 */
NumberD *Xray::GetNumber(int x)
{
    for( auto number : mItems )
    {
        if(x == number->GetValue())
            return number;
    }

    return nullptr;
}

/**
 * Remove item from xray
 * @param number
 */
void Xray::RemoveItem(NumberD *number)
{
    mContains--;

    auto loc = find(begin(mItems), end(mItems), number);
    if (loc != end(mItems))
    {
        mItems.erase(loc);
    }
}
