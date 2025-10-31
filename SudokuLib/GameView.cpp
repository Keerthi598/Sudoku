/**
 * @file GameView.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "GameView.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

/// Frame duration in milliseconds
const int FrameDuration = 25;

/// Level Zero
const wxString levelZero = "levels/level0.xml";

/// Level One
const wxString levelOne = "levels/level1.xml";

/// Level Two
const wxString levelTwo = "levels/level2.xml";


/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY,wxDefaultPosition, wxDefaultSize,wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    Bind(wxEVT_TIMER, &GameView::OnTimer, this);
    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
    Bind(wxEVT_KEY_DOWN, &GameView::OnKey, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);

    mStopWatch.Start();


}

/**
 * Paint event, draws the window
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent &event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mGame.Update(elapsed);

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();

    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}


/**
 * Refresh screen
 * @param event
 */
void GameView::OnTimer(wxTimerEvent &event)
{
    Refresh();

    if (!mGame.Advance())
        return;

    int curr = mGame.CurrLevel();

    int next = curr + 1;

    next = (next > 3) ? 3 : next;

    Load(next);
}


/**
 * Handle key event
 * @param event
 */
void GameView::OnKey(wxKeyEvent &event)
{

    if (event.GetKeyCode() == WXK_SPACE)
    {
        //Code to eat
        mGame.Eat();
    }

    else if(event.GetKeyCode() >= wxKeyCode('0') && event.GetKeyCode() <= wxKeyCode('8'))
    {
        mGame.Regurgitate(event.GetKeyCode()- wxKeyCode('0') );
    }


    else if (event.GetUnicodeKey() == 66) // If B is Pressed
    {
        mGame.HeadButt();
    }


    event.Skip();
}


/**
 * Load file
 * @param filename
 */
void GameView::Load(int levelNumber)
{
    mGame.Clear();

    std::wstring filename;

    if (levelNumber == 0)
        filename = levelZero;

    else if (levelNumber == 1)
        filename = levelOne;

    else if (levelNumber == 2)
        filename = levelTwo;

    // Level 3 placeholder
    else
        return;

    mGame.Load(filename, levelNumber);

    Refresh();
}


/**
 * Event handler for single left click
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
    mGame.OnLeftDown(event.GetX(), event.GetY());
    event.Skip();
}

/**
 * Event handler for left mouse up
 * @param event
 */
void GameView::OnLeftUp(wxMouseEvent &event)
{
}

/**
 * Solve the current board
 */
void GameView::Solve()
{
    mGame.Solve();
}




