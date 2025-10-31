/**
 * @file DeclarationXray.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "DeclarationXray.h"

/**
 * Constructor
 * @param width
 * @param height
 * @param image
 * @param capacity
 */
DeclarationXray::DeclarationXray(int width, int height, std::wstring image, int capacity) : Declaration(width, height, image)
{
    mCapacity = capacity;
}
