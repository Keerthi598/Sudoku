/**
 * @file Declaration.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"

#include "Declaration.h"

/**
 * Constructor
 * @param width
 * @param height
 * @param image
 */
Declaration::Declaration(int width, int height, std::wstring image)
{
    mWidth = width;
    mHeight = height;
    mImage = image;
}