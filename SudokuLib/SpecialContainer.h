/**
 * @file SpecialContainer.h
 * @author Keerthi Vardhan
 *
 * Class for special containers like pumpkin and cauldron
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SPECIALCONTAINER_H
#define ACTIONSUDOKU_SUDOKULIB_SPECIALCONTAINER_H

#include "Container.h"
#include "NumberD.h"

#include <vector>

/**
 * Special container class
 */
class SpecialContainer : public Container
{
private:
    /// Image of container front
    std::unique_ptr<wxImage> mFrontImage;

    /// Bitmap of container front
    std::unique_ptr<wxBitmap> mFrontBitMap;

    bool mIsBroken = false;  ///< Indicate if container is broken

    /// Items contained in this container
    std::vector<std::shared_ptr<NumberD>> mContains;


public:
    SpecialContainer(Game *game);

    /**
     * Add items to container
     * @param num
     */
    void Add(std::shared_ptr<NumberD> num) { mContains.push_back(num); }

    void XmlLoad(std::shared_ptr<Declaration> dec) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Accept(ItemVisitor* visitor) override;

    /**
     * Determine whether this special container is broken
     * @return Whether this special container is broken
     */
    bool GetBroken() const { return mIsBroken; }

    /**
     * Indicate whether this special container is broken
     * @param isBroken Indicates whether this special container is broken
     */
     void SetBroken(bool isBroken) { mIsBroken = isBroken; }
};

#endif //ACTIONSUDOKU_SUDOKULIB_SPECIALCONTAINER_H
