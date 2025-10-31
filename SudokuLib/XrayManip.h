/**
 * @file XrayManip.h
 * @author Keerthi Vardhan
 *
 * Visitor class to do stuff in xray
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_XRAYMANIP_H
#define ACTIONSUDOKU_SUDOKULIB_XRAYMANIP_H

#include "ItemVisitor.h"

/**
 * Visitor to work in Xray
 */
class XrayManip : public ItemVisitor
{
private:
    /// The xray of the game
    Xray* mXray = nullptr;

public:
    XrayManip();

    void VisitXray(Xray* xray) override;

    bool IsFull();

    void AddToXray(NumberD* number);

    void RemoveFromXray(NumberD* number);

    NumberD* GetNumber(int x);

};

#endif //ACTIONSUDOKU_SUDOKULIB_XRAYMANIP_H
