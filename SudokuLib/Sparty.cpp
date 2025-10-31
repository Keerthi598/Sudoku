/**
 * @file Sparty.cpp
 * @author Ali Abboodi
 */

#include "pch.h"
#include "Sparty.h"
#include "Game.h"
#include "ItemVisitor.h"

#include <cmath>

using namespace std;

/// Character speed in pixels per second
const double MaxSpeed = 400.00;

/// The time for an eating cycles in seconds
const double EatingTime = 0.5;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.5;


/**
 * Sparty Constructor
 * @param game The game that Sparty belongs to
 */
Sparty::Sparty(Game *game) : Item(game)
{
    game->SetSparty(this);
}

/**
 * Draw Sparty
 * @param graphics The device context to draw on
 */
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mCurrMAngle == 0 && mCurrHAngle == 0)
    {
        graphics->PushState();
        graphics->Translate(mX, mY);

        if (mFront == 1)
        {
            graphics->DrawBitmap(*mBSpartyM, 0, 0, mWid, mHgt);
            graphics->DrawBitmap(*mBSpartyH, 0, 0, mWid, mHgt);
        }

        else
        {
            graphics->DrawBitmap(*mBSpartyH, 0, 0, mWid, mHgt);
            graphics->DrawBitmap(*mBSpartyM, 0, 0, mWid, mHgt);
        }

        graphics->PopState();
    }

    else if(mCurrMAngle > 0)
    {
        DrawEating(graphics);
    }

    else if(mCurrHAngle > 0)
        DrawHeadButting(graphics);

}


/**
 * Draw Eating animation
 * @param graphics
 */
void Sparty::DrawEating(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    graphics->Translate(mX, mY);

    if (mFront == 1)
    {
        graphics->PushState();

        graphics->Translate(int(mMpx), int(mMpy));
        graphics->Rotate(mCurrMAngle);
        graphics->Translate(-mMpx, -mMpy);

        graphics->DrawBitmap(*mBSpartyM, 0, 0, mWid, mHgt);

        graphics->PopState();
        //End of rotating mouth

        graphics->DrawBitmap(*mBSpartyH, 0, 0, mWid, mHgt);
    }

    else
    {
        graphics->DrawBitmap(*mBSpartyH, 0, 0, mWid, mHgt);
        //Rotate mouth
        graphics->PushState();

        graphics->Translate(int(mMpx), int(mMpy));
        graphics->Rotate(mCurrMAngle);
        graphics->Translate(-mMpx, -mMpy);

        graphics->DrawBitmap(*mBSpartyM, 0, 0, mWid, mHgt);

        graphics->PopState();
    }

    graphics->PopState();
}

/**
 * Draw HeadButting animation
 * @param graphics
 */
void Sparty::DrawHeadButting(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    graphics->Translate(mX, mY);

    if (mFront == 1)
    {
        graphics->PushState();

        graphics->Translate(int(mHpx), int(mHpy));
        graphics->Rotate(mCurrHAngle);
        graphics->Translate(-mHpx, -mHpy);

        graphics->DrawBitmap(*mBSpartyM, 0, 0, mWid, mHgt);
        graphics->DrawBitmap(*mBSpartyH, 0, 0, mWid, mHgt);

        graphics->PopState();

    }

    else
    {
        graphics->PushState();

        graphics->Translate(int(mHpx), int(mHpy));
        graphics->Rotate(mCurrHAngle);
        graphics->Translate(-mHpx, -mHpy);

        graphics->DrawBitmap(*mBSpartyH, 0, 0, mWid, mHgt);
        graphics->DrawBitmap(*mBSpartyM, 0, 0, mWid, mHgt);

        graphics->PopState();
    }

    graphics->PopState();
}

/**
 * Load sparty from Xml
 * @param dec
 */
void Sparty::XmlLoad(std::shared_ptr<Declaration> dec)
{
    //Item::XmlLoad(dec);
    mWid = dec->GetWidth();
    mHgt = dec->GetHeight();

    SetImages(dec->GetImages());
    SetPivot(dec->GetPivot());

    auto target = dec->GetTarget();

    mFront = target[0];
    mTx = target[1];
    mTy = target[2];

    mMouthSpeed = mMpa / (EatingTime * 0.5);
    mHeadSpeed = mHpa / (HeadbuttTime * 0.5);

    mCurrSpeed.x = 0;
    mCurrSpeed.y = 0;

    mCurrTarget.x = 0;
    mCurrSpeed.y = 0;
}

/**
 * Set sparty images
 * @param images vector of images
 */
void Sparty::SetImages(std::vector<std::wstring> images)
{
    if (!images[0].empty())
    {
        wstring imageName = Item::GetGame()->GetImgDir() + L"/" + images[0];
        mISpartyH = make_unique<wxImage>(imageName, wxBITMAP_TYPE_ANY);
        mBSpartyH = make_unique<wxBitmap>(*mISpartyH);
    }
    else
    {
        mISpartyH.release();
        mBSpartyH.release();
    }

    if (!images[1].empty())
    {
        wstring imageName = Item::GetGame()->GetImgDir() + L"/" + images[1];
        mISpartyM = make_unique<wxImage>(imageName, wxBITMAP_TYPE_ANY);
        mBSpartyM = make_unique<wxBitmap>(*mISpartyM);
    }
    else
    {
        mISpartyM.release();
        mBSpartyM.release();
    }
}

/**
 * Set the pivot information
 * @param pivot
 */
void Sparty::SetPivot(std::vector<double> pivot)
{
    mHpa = pivot[0];
    mHpx = pivot[1];
    mHpy = pivot[2];

    mMpa = pivot[3];
    mMpx = pivot[4];
    mMpy = pivot[5];
}


/**
 * Start eating animation
 */
void Sparty::Eat()
{
    if (mCurrSpeed.x != 0 || mCurrSpeed.y != 0 || mCurrHAngle != 0)
        return;                                   // Don't initiate eating while moving or headbutting

    mCurrMAngle = mMouthSpeed * 0.001;
    mPrevAngle = 0;
}

/**
 * Start headbutting animation
 */
void Sparty::HeadButt()
{
    if (mCurrSpeed.x != 0 || mCurrSpeed.y != 0  || mCurrMAngle != 0)
        return;                                   // Don't initiate headbutting while moving or eating

    mCurrHAngle = mHeadSpeed * 0.001;
    mPrevHAngle = 0;
}

/**
 * Start movement
 * @param x
 * @param y
 */
void Sparty::Move(double x, double y)
{
    mCurrTarget.x = x - mTx;
    mCurrTarget.y = y + mTy - mHgt;

    mCurrTarget.x = (mCurrTarget.x >= 0) ? mCurrTarget.x : 0;
    //mCurrTarget.y = (mCurrTarget.y >= 0) ? mCurrTarget.y : 0;

    double dx = mCurrTarget.x - mX;
    double dy = y + mTy - mHgt - mY;



    double dist = sqrt((dx*dx) + (dy*dy));

    double time = dist / MaxSpeed;

    mCurrSpeed.x = dx / time;
    mCurrSpeed.y = dy / time;
}


/**
 * Update sparty
 * @param elapsed
 */
void Sparty::Update(double elapsed)
{
    if(mCurrSpeed.x == 0 && mCurrSpeed.y == 0)
    {
        //Skip to check if eating
    }

    else if(std::abs(mX - mCurrTarget.x) < 1 && std::abs(mY - mCurrTarget.y) < 1)
    {
        mCurrSpeed.x = 0;
        mCurrSpeed.y = 0;
    }

    else
    {
        mX += (mCurrSpeed.x * elapsed);
        mY += (mCurrSpeed.y * elapsed);

        if (mCurrSpeed.x > 0)
        {
            mX = (mX >= mCurrTarget.x) ? mCurrTarget.x : mX;
        }

        if (mCurrSpeed.y > 0)
        {
            mY = (mY >= mCurrTarget.y) ? mCurrTarget.y : mY;
        }

        if (mCurrSpeed.x < 0)
        {
            mX = (mX <= mCurrTarget.x) ? mCurrTarget.x : mX;
        }

        if (mCurrSpeed.y < 0)
        {
            mY = (mY <= mCurrTarget.y) ? mCurrTarget.y : mY;
        }

    }

    //Eating
    if(mCurrMAngle == 0)
    {
        //return;
    }

    else if(mCurrMAngle >= mMpa || mCurrMAngle < mPrevAngle)
    {
        mPrevAngle = mCurrMAngle;
        mCurrMAngle -= (mMouthSpeed * elapsed);
        mCurrMAngle = (mCurrMAngle > 0) ? mCurrMAngle : 0;
    }

    else if(mCurrMAngle > 0)
    {
        mPrevAngle = mCurrMAngle;
        mCurrMAngle += (mMouthSpeed * elapsed);
    }


    //Headbutting
    if(mCurrHAngle == 0)
    {
        return;
    }

    else if(mCurrHAngle >= mHpa || mCurrHAngle < mPrevHAngle)
    {
        mPrevHAngle = mCurrHAngle;
        mCurrHAngle -= (mHeadSpeed * elapsed);
        mCurrHAngle = (mCurrHAngle > 0) ? mCurrHAngle : 0;
    }

    else if(mCurrHAngle > 0)
    {
        mPrevHAngle = mCurrHAngle;
        mCurrHAngle += (mHeadSpeed * elapsed);
    }


}

/**
 * Accept Visitor
 * @param visitor
 */
void Sparty::Accept(ItemVisitor *visitor)
{
    visitor->VisitSparty(this);
}
