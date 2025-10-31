/**
 * @file XrayManip.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "XrayManip.h"
#include "Xray.h"

/**
 * Constructor
 */
XrayManip::XrayManip() : ItemVisitor()
{
}

/**
 * Visit xray
 * @param xray
 */
void XrayManip::VisitXray(Xray *xray)
{
    mXray = xray;
}

/**
 * Check if xray is full
 * @return true if xray is full
 */
bool XrayManip::IsFull()
{
    return mXray->IsFull();
}

/**
 * Add number to xray
 * @param number
 */
void XrayManip::AddToXray(NumberD* number)
{
    mXray->AddItem(number);
}

/**
 * Remove item from xray
 * @param number
 */
void XrayManip::RemoveFromXray(NumberD *number)
{
    mXray->RemoveItem(number);
}

/**
 * Get the number from xray if it exists
 * @param x The value
 * @return Number
 */
NumberD *XrayManip::GetNumber(int x)
{
    return mXray->GetNumber(x);
}
