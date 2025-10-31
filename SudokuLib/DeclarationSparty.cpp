/**
 * @file DeclarationSparty.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "DeclarationSparty.h"



/**
 * Constructor
 * @param width
 * @param height
 * @param target Front, target-x and target-y
 * @param pivot Hpa, hpx, hpy, mpa, mpx, mpy
 * @param images img1, img2
 */
DeclarationSparty::DeclarationSparty(int width,
                                     int height,
                                     std::vector<int> target,
                                     std::vector<double> pivot,
                                     std::vector<std::wstring> images):
    Declaration(width, height, L"")
{
    mTarget = target;
    mPivot = pivot;
    mImages = images;
}
