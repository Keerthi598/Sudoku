/**
 * @file BoardNumber.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "BoardNumber.h"
#include "NumberG.h"

/**
 * Constructor
 * @param point The co ords to be checked
 */
BoardNumber::BoardNumber(wxPoint point) : ItemVisitor()
{
    mPoint = point;
}

/**
 * Find Number on given board co ords
 * @param given
 */
void BoardNumber::VisitGiven(NumberG *given)
{
    if(mNumber != nullptr)
        return;

    if(given->HitTest(mPoint.x, mPoint.y))
        mNumber = given;
}
