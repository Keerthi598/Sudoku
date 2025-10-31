/**
 * @file NumberG.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"

#include "NumberG.h"
#include "ItemVisitor.h"

using namespace std;


/**
 * Constructor
 * @param game The game, this is a part of
 */
NumberG::NumberG(Game *game) : Item(game)
{
}

/**
 * Draw this item
 * @param graphics The device to draw on
 */
void NumberG::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
}



/**
 * Load the item from the xml
 * @param dec The declaration for this item
 */
void NumberG::XmlLoad(std::shared_ptr<Declaration> dec)
{
    Item::XmlLoad(dec);
    mValue = dec->GetValue();
}


/**
 * Accept a visitor
 * @param visitor
 */
void NumberG::Accept(ItemVisitor *visitor)
{
    visitor->VisitGiven(this);
}
