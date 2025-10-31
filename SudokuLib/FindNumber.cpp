/**
 * @file FindNumber.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "FindNumber.h"
#include "NumberD.h"

/**
 * Constructor
 * @param target The co ords to be checked
 */
FindNumber::FindNumber(wxPoint target) : ItemVisitor()
{
    mTarget = target;
}

/**
 * Find if can be eaten
 * @param digit
 */
void FindNumber::VisitDigit(NumberD *digit)
{
    if(mDigit != nullptr)        //If another digit is found
        return;

    auto container = digit->GetContainer();

    if (container != nullptr)    //If it is in a container
        return;

    if (!digit->HitTest(mTarget.x, mTarget.y))
        return;                  //If the digit is not in the spot

    mDigit = digit;
}
