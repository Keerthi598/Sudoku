/**
 * @file NumberG.h
 * @author Keerthi Vardhan
 *
 * Class for a given number
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_NUMBERG_H
#define ACTIONSUDOKU_SUDOKULIB_NUMBERG_H

#include <string>
#include <memory>
#include "Item.h"

/**
 * Class for a given number
 */
class NumberG : public Item
{
private:
    /// The value of the given number
    int mValue;

protected:
    /// Indicate item is on main board
    bool mOnBoard = true;

public:
    NumberG(Game *game);

    /// Default constructor(disable)
    NumberG() = delete;

    /// Copy constructor(disabled)
    NumberG(const NumberG &) = delete;

    /**
     * Get the value of this digit
     * @return value
     */
    int GetValue() {return mValue;}

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    virtual void XmlLoad(std::shared_ptr<Declaration> dec) override;

    /**
     * Indicate if number is on board
     * @return
     */
    bool OnBoard() { return mOnBoard; }

    void Accept(ItemVisitor* visitor) override;
};

#endif //ACTIONSUDOKU_SUDOKULIB_NUMBERG_H
