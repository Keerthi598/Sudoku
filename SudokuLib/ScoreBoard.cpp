/**
 * @file ScoreBoard.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "ScoreBoard.h"

#include <wx/graphics.h>


using namespace std;

/// Size of the scoreboard text in virtual pixels
const int ScoreboardTextSize = 64;

///Top left corner of the scoreboard in virtual pixels
const wxPoint ScoreboardTopLeft(10, 10);

/// Number of seconds in a minute
const int seconds = 60;

/**
 * Start the timer
 */
void ScoreBoard::Start()
{
    mIsRunning = true;
    mCurrTime = 0;
}

/**
 * Update the timer
 * @param elapsed
 */
void ScoreBoard::Update(double elapsed)
{
    if (!mIsRunning)
        return;

    mCurrTime += elapsed;
}


/**
 * Draw the board
 * @param graphics
 */
void ScoreBoard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int m = int(mCurrTime / seconds);
    int s = int(mCurrTime) % 60;

    wstring min = to_wstring(m);
    wstring sec = to_wstring(s);

    if (s < 10)
        sec = L"0" + sec;

    wstring time = min + L":" + sec;

    wxFont font(wxSize(0, ScoreboardTextSize),
                   wxFONTFAMILY_SWISS,
                   wxFONTSTYLE_NORMAL,
                   wxFONTWEIGHT_BOLD);

    graphics->SetFont(font, wxColour(245, 245, 245));

    graphics->DrawText(time, ScoreboardTopLeft.x, ScoreboardTopLeft.y);
}

/**
 * Stop the timer
 */
void ScoreBoard::Stop()
{
    mIsRunning = false;
}
