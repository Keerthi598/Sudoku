/**
 * @file ItemVisitor.h
 * @author Keerthi Vardhan
 *
 * Visitor Base Class
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_ITEMVISITOR_H
#define ACTIONSUDOKU_SUDOKULIB_ITEMVISITOR_H

// Forward references
class Background;
class Container;
class Xray;
class SpecialContainer;
class NumberG;
class NumberD;
class Sparty;

/**
 * Vistior Base Class
 */
class ItemVisitor
{
protected:
    /**
     * Constructor
     * Ensures this is an abstract class
     */
    ItemVisitor() {}

public:
    virtual ~ItemVisitor();

    /**
     * Visit background item
     * @param background
     */
    virtual void VisitBackground(Background* background) {}

    /**
     * Visit container item
     * @param container
     */
    virtual void VisitContainer(Container* container) {}

    /**
     * Visit xray item
     * @param xray
     */
    virtual void VisitXray(Xray* xray) {}

    /**
     * Visit special container item
     * @param spCont
     */
    virtual void VisitSpecialContainer(SpecialContainer* spCont) {}

    /**
     * Visit Given number item
     * @param given
     */
    virtual void VisitGiven(NumberG* given) {}

    /**
     * Visit Digit item
     * @param digit
     */
    virtual void VisitDigit(NumberD* digit) {}

    /**
     * Visit sparty item
     * @param sparty
     */
    virtual void VisitSparty(Sparty* sparty) {}

};

#endif //ACTIONSUDOKU_SUDOKULIB_ITEMVISITOR_H
