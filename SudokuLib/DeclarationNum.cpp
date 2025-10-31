/**
 * @file DeclarationNum.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "DeclarationNum.h"

/**
 * Constructor
 * @param width The width of this item
 * @param height The height of this item
 * @param image The image filename
 * @param value The value of this item
 */
DeclarationNum::DeclarationNum(int width, int height, std::wstring image, int value) : Declaration(width, height, image)
{
    mValue = value;
}

