/**
 * @file FindGivens.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "FindGivens.h"
#include "NumberG.h"

/**
 * Constructor
 */
FindGivens::FindGivens() : ItemVisitor()
{
}

/**
 * Count number of givens
 * @param given
 */
void FindGivens::VisitGiven(NumberG *given)
{
    if (given->OnBoard())
        mGiven++;
}

