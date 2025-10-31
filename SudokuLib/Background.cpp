/**
 * @file Background.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "Background.h"
#include "ItemVisitor.h"

using namespace std;

/**
 * Constructor
 * @param game The game, this item is a part of
 */
Background::Background(Game *game) : Item(game)
{
}


/**
 * Draw this item
 * @param graphics
 */
void Background::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
}


/**
 * Load this item from xml
 * @param dec The declaration for this class
 */
void Background::XmlLoad(std::shared_ptr<Declaration> dec)
{
    Item::XmlLoad(dec);
}


/**
 * Accept visitor
 * @param visitor
 */
void Background::Accept(ItemVisitor *visitor)
{
    visitor->VisitBackground(this);
}
