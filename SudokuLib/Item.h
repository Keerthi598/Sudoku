/**
 * @file Item.h
 * @author Keerthi Vardhan
 *
 * Base Item class
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_ITEM_H
#define ACTIONSUDOKU_SUDOKULIB_ITEM_H

#include <memory>
#include <wx/graphics.h>
#include "Declaration.h"

class Game;
class Xray;
class ItemVisitor;

/**
 * The base item in the game
 */
class Item
{
private:
    ///the game, this item is a part of
    Game* mGame;

    double mX = 0;   ///< The x location of the item
    double mY = 0;   ///< The y location of the item

    std::unique_ptr<wxImage> mItemImage;   ///< The image of the item
    std::unique_ptr<wxBitmap> mItemBitmap; ///< the bitmap of the item

    double mWidth;   ///< The width of the item
    double mHeight;  ///< The height of the item


protected:
    Item(Game *game);

    /**
     * Set Width for testing
     * @param w Width
     */
    void SetWidth(double w) {mWidth = w;}

    /**
     * Set height for testing
     * @param h Height
     */
    void SetHeight(double h) {mHeight = h;}


public:

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    virtual ~Item();

    /**
     * The X location of the item
     * @return X location in pixels
     */
    virtual double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    virtual double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y - mHeight; }

    /**
     * Get the width of the item
     * @return width in pixels
     */
    double GetWidth() const {return mWidth; }


    /**
     * Get the height of the item
     * @return height in pixels
     */
    double GetHeight() const {return mHeight; }

    void SetImage(std::wstring image);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);


    /**
     * Update screen
     * @param elapsed
     */
    virtual void Update(double elapsed) {}

    /**
     * Get the game this item is a part of
     * @return game pointer
     */
    Game* GetGame() { return mGame; }

    virtual void XmlLoad(std::shared_ptr<Declaration> dec);

    virtual bool HitTest(double x, double y);


    // Visitor
    /**
     * Accept visitor
     * Purely virtual
     * @param visitor
     */
    virtual void Accept(ItemVisitor* visitor) = 0;

};

#endif //ACTIONSUDOKU_SUDOKULIB_ITEM_H
