/**
 * @file ScreenText.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"

#include "ScreenText.h"
#include "wx/graphics.h"


/**
 * Text for level completeion
 * @param graphics
 * @param w
 * @param h
 */
void ScreenText::LevelCompleteText(std::shared_ptr<wxGraphicsContext> graphics, double w, double h)
{
    wxFont bigFont(wxSize(0, 100),
                   wxFONTFAMILY_SWISS,
                   wxFONTSTYLE_NORMAL,
                   wxFONTWEIGHT_BOLD);
    graphics->SetFont(bigFont, wxColour(10, 171, 29));
    // I used a color picker tool to get this color - Keerthi

    double wid, hit;
    graphics->GetTextExtent(L"Level Complete!", &wid, &hit);
    graphics->DrawText(L"Level Complete!", w/2 - wid/2, h/2 - hit/2);
}


/**
 * Text for level incorrect
 * @param graphics
 * @param w
 * @param h
 */
void ScreenText::LevelIncorrectText(std::shared_ptr<wxGraphicsContext> graphics, double w, double h)
{
    wxFont bigFont(wxSize(0, 100),
                   wxFONTFAMILY_SWISS,
                   wxFONTSTYLE_NORMAL,
                   wxFONTWEIGHT_BOLD);
    graphics->SetFont(bigFont, wxColour(10, 171, 29));
    // I used a color picker tool to get this color - Keerthi

    double wid, hit;
    graphics->GetTextExtent(L"Incorrect!", &wid, &hit);
    graphics->DrawText(L"Incorrect!", w/2 - wid/2, h/2 - hit/2);
}

/**
 * Draw the
 */
void ScreenText::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, double w, double h)
{
    if (mTime == 0)
        return;

    if (mIsCorrect)
        LevelCompleteText(graphics, w, h);

    else if (mInCorrect)
        LevelIncorrectText(graphics, w, h);

}

/**
 * Update screen text
 * @param elapsed
 */
void ScreenText::Update(double elapsed)
{
    if(mTime > 0)
    {
        mTime += elapsed;

        if (mTime >= 3)
        {
            mTime = 0;
            mInCorrect = false;

            if (mIsCorrect)
            {
                mIsCorrect = false;
                // Go to next level code
                mAdvanceLevel = true;
            }
        }

        return;
    }
}

/**
 * True if level is complete and should move to the next level
 * @return bool
 */
bool ScreenText::AdvanceLevel()
{
    if (!mAdvanceLevel)
        return false;

    mAdvanceLevel = false;
    return true;
}
