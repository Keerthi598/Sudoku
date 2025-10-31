/**
 * @file Background.h
 * @author Keerthi Vardhan
 *
 * Class for background item
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_BACKGROUND_H
#define ACTIONSUDOKU_SUDOKULIB_BACKGROUND_H

#include <string>
#include <memory>
#include "Item.h"

/**
 * Class for item background
 */
class Background : public Item
{
private:

public:
    Background(Game *game);

    ///  Default constructor (disabled)
    Background() = delete;

    ///  Copy constructor (disabled)
    Background(const Background &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void XmlLoad(std::shared_ptr<Declaration> dec) override;


    void Accept(ItemVisitor* visitor) override;
};

#endif ACTIONSUDOKU_SUDOKULIB_BACKGROUND_H
