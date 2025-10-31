/**
 * @file Xray.h
 * @author Keerthi Vardhan
 *
 * Class for Xray item
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_XRAY_H
#define ACTIONSUDOKU_SUDOKULIB_XRAY_H

#include "Container.h"
#include <vector>
#include <random>

class NumberD;

/**
 * Xray class
 */
class Xray : public Container
{
private:
    /// Max holding capacity of this item
    int mCapacity;

    /// Current number of item in Xray
    int mContains = 0;

    /// Items in xray
    std::vector<NumberD*> mItems;

    /// Random number generator
    std::mt19937 mRandom;


    std::uniform_real_distribution<> mDistributionX; ///< Potential x co ords
    std::uniform_real_distribution<> mDistributionY; ///< Potential y co ords

protected:
    /**
     * Set capacity manually
     * Purely for testing
     * @param x
     */
    void SetCap(int x) {mCapacity = x;}

public:
    Xray(Game* game);

    /// Default constructor (disabled)
    Xray() = delete;

    /**
     * Indicate if xray has reached max capacity
     * @return
     */
    bool IsFull() { return mCapacity == mContains; }

    /// Copy constructor (disabled)
    Xray(const Xray &) = delete;

    void XmlLoad(std::shared_ptr<Declaration> dec) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void AddItem(NumberD* number);

    void RemoveItem(NumberD* number);

    NumberD* GetNumber(int x);

    void Accept(ItemVisitor* visitor) override;
};

#endif //ACTIONSUDOKU_SUDOKULIB_XRAY_H
