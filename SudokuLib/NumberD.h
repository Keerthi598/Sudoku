/**
 * @file NumberD.h
 * @author Keerthi Vardhan
 *
 * Class for an interactable  number
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_NUMBERD_H
#define ACTIONSUDOKU_SUDOKULIB_NUMBERD_H

#include <string>
#include <memory>
#include "NumberG.h"


class Container;

/**
 * Class for an interactable number
 */
class NumberD : public NumberG
{
private:
    ///Container
    Container* mContainer = nullptr;

protected:
    /**
     * Get this pointer
     * @return this pointer
     */
    NumberD* GetThis() {return this;}

public:
    NumberD(Game* game);

    /// Default constructor(disabled)
    NumberD() = delete;

    /// Copy constructor(disabled)
    NumberD(const NumberD &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void ContainerDraw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Toggle on or off board
     */
    void SwitchBoard() {mOnBoard = !mOnBoard;}

    /**
     * Set the container this digit is contained in
     * @param container
     */
    void SetContainer(Container* container) {mContainer = container;}

    /**
     * Get the container
     * @return container
     */
    Container* GetContainer() { return mContainer; }

    /**
     * Load the xml and place digit off board
     * @param dec
     */
    void XmlLoad(std::shared_ptr<Declaration> dec) {NumberG::XmlLoad(dec); SwitchBoard();}

    void Accept(ItemVisitor* visitor) override;

};

#endif //ACTIONSUDOKU_SUDOKULIB_NUMBERD_H
