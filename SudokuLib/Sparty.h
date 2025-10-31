/**
 * @file Sparty.h
 * @author Ali Abboodi
 *
 * Class for the sparty item
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SPARTY_H
#define ACTIONSUDOKU_SUDOKULIB_SPARTY_H

#include <string>
#include <memory>
#include <vector>
#include <wx/gdicmn.h>
#include "Item.h"


/**
 * Sparty class
 */
class Sparty: public Item
{
private:

    std::unique_ptr<wxImage> mISpartyH;   ///< The image of sparty head
    std::unique_ptr<wxBitmap> mBSpartyH; ///<  The bitmap of sparty head

    std::unique_ptr<wxImage> mISpartyM;   ///< The image of sparty mouth
    std::unique_ptr<wxBitmap> mBSpartyM; ///<  The bitmap of sparty mouth

    int mFront;   ///< Decide the image on front

    int mWid;   ///< The width
    int mHgt;   ///< The height

    int mTx;    ///< Target x
    int mTy;    ///< Target y

    double mHpa; ///< Head pivot angle
    double mHpx; ///< Head pivot x co ords
    double mHpy; ///< Head pivot y co ords

    double mMpa; ///< Mouth pivot angle
    double mMpx; ///< Mouth pivot x co ords
    double mMpy; ///< Mouth pivot y co ords

    double mX; ///< x co ords of sparty
    double mY; ///< y co ords of sparty

    double mCurrMAngle = 0;   ///< The current angle of sparty's mouth
    double mPrevAngle = 0;    ///< The previous angle of sparty's mouth
    double mMouthSpeed;       ///< The speed of mouth angle movement

    double mCurrHAngle = 0;   ///< The current angle of sparty's head
    double mPrevHAngle = 0;   ///< The previous angle of sparty's head
    double mHeadSpeed;        ///< The speed of head angle movement

    wxPoint mCurrSpeed;       ///< The current speed of sparty
    wxPoint mCurrTarget;      ///< The current target for sparty


public:
    /// Default constructor (disabled)
    Sparty() = delete;

    /// Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    /// Assignment operator
    void operator=(const Sparty &) = delete;

    void Eat();

    void HeadButt();

    void Move(double x, double y);

    void Update(double elapsed) override;

    Sparty(Game *game);

    void SetImages(std::vector<std::wstring> images);

    void SetPivot(std::vector<double> pivot);

    //double GetX() const override { return mCurrTarget.x; }

    //double GetY() const override{ return mCurrTarget.y; }

    /**
     * Set the sparty location
     * @param x
     * @param y
     */
    void SetLocation(double x, double y) override { mX = x; mY = y - mHgt; }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void DrawEating(std::shared_ptr<wxGraphicsContext> graphics);

    void DrawHeadButting(std::shared_ptr<wxGraphicsContext> graphics);

    virtual void XmlLoad(std::shared_ptr<Declaration> dec) override;


    /**
     * Get the target point at current location
     * @return wxPoint
     */
    wxPoint GetTarget(){return wxPoint(mX + mTx, mY + mHgt - mTy);}

    /**
     * Get current target
     * Only for testing
     * @return
     */
    wxPoint GetT() {return mCurrTarget;}

    /**
     * True if sparty is moveing
     * @return
     */
    bool IsMoving() {if(mCurrSpeed.x != 0 || mCurrSpeed.y != 0) return true; return false;}

    void Accept(ItemVisitor* visitor) override;
};

#endif //ACTIONSUDOKU_SUDOKULIB_SPARTY_H
