/**
 * @file Container.h
 * @author Keerthi Vardhan
 *
 * Base Class for a container item
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_CONTAINER_H
#define ACTIONSUDOKU_SUDOKULIB_CONTAINER_H

#include <string>
#include <memory>
#include "Item.h"
#include "NumberD.h"


/**
 * Base Class for a container item
 */
class Container : public Item
{
private:
    /// Number of items currently in this container
    int mContains = 0;

    //std::vector<NumberD*> mItems;

protected:
    Container(Game *game);

public:

    /**
     * Add an item to this collection
     */
    void AddItem(NumberD*);

    /**
     * Get the number of items currently contained in this container
     * @return
     */
    int GetNum() { return mContains; }


    //std::vector<NumberD*> GetItems()  {return mItems;}

    //void removeItem(NumberD *x);


    virtual void Accept(ItemVisitor* visitor) override;

};

#endif //ACTIONSUDOKU_SUDOKULIB_CONTAINER_H
