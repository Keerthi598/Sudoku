/**
 * @file NumberD.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "NumberD.h"
#include "Xray.h"
#include "ItemVisitor.h"


/**
 * Constructor
 * @param game
 */
NumberD::NumberD(Game *game) : NumberG(game)
{
}

/**
 * Draw object if not in container
 * @param graphics
 */
void NumberD::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if( mContainer != nullptr )
        return;

    Item::Draw(graphics);
}

/**
 * Draw Item in a container
 * @param graphics
 */
void NumberD::ContainerDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
}





/**
 * Accept Visitor
 * @param visitor
 */
void NumberD::Accept(ItemVisitor *visitor)
{
    NumberG::Accept(visitor);
    visitor->VisitDigit(this);
}
