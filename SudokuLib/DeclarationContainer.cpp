/**
 * @file DeclarationContainer.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "DeclarationContainer.h"

/**
 * Constructor
 * @param width The width of this item
 * @param height The height of this item
 * @param image The image of this item
 * @param front The front image of this container
 */
DeclarationContainer::DeclarationContainer(int width, int height, std::wstring image, std::wstring front) : Declaration(width, height, image)
{
    mFront = front;
}
