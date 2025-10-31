/**
 * @file SolveVisitor.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "SolveVisitor.h"
#include "NumberD.h"
#include "PlayableArea.h"

/**
 * Constructor
 * @param point The point to be added to
 * @param val The value to be added
 * @param playableArea The playable area
 */
SolveVisitor::SolveVisitor(wxPoint point, int val, PlayableArea* playableArea) : ItemVisitor()
{
    mPoint = point;
    mVal = val;
    mPlayableArea = playableArea;
}

/**
 * Find digit with value and put it in location
 * @param digit
 */
void SolveVisitor::VisitDigit(NumberD *digit)
{
    if (mAdded)                      //If an item is already added to the space
        return;

    if (mVal != digit->GetValue())   //If value does not match
        return;

    if (digit->OnBoard() || digit->GetContainer() != nullptr)
        return;                      //Digit already on board or in a container

    // Find Loc

    wxPoint pos = mPlayableArea->GetTargetCords(mPoint);

    digit->SetLocation(pos.x, pos.y);
    digit->SwitchBoard();

    mAdded = true;
    mPlayableArea->AddToBoard();
}
