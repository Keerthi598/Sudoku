/**
 * @file Container.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "Container.h"
#include "Item.h"
#include "ItemVisitor.h"

/**
 * Constructor
 * @param game
 */
Container::Container(Game *game) : Item(game)
{
}

/*
void Container::AddItem(NumberD* x) {
    mContains++;
    mItems.push_back(x);
}

void Container::removeItem(NumberD *x) {
    mContains--;
    auto loc = find(std::begin(mItems), std::end(mItems), x);
    if (loc != std::end(mItems))
    {
        mItems.erase(loc);
    }
}
*/


/**
 * Accept visitor
 * @param visitor
 */
void Container::Accept(ItemVisitor *visitor)
{
    visitor->VisitContainer(this);
}

