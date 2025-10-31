/**
 * @file GameView.h
 * @author Keerthi Vardhan
 *
 * The game view class
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_GAMEVIEW_H
#define ACTIONSUDOKU_SUDOKULIB_GAMEVIEW_H

#include "Game.h"

/**
 * The view class for the game
 */
class GameView: public wxWindow
{
private:
    ///The game contained in this view
    Game mGame;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    void OnPaint(wxPaintEvent& event);

public:
    void Initialize(wxFrame* parent);

    void Load(int levelNumber);

    void OnTimer(wxTimerEvent &event);

    void OnKey(wxKeyEvent &event);

    void OnLeftDown(wxMouseEvent &event);

    void OnLeftUp(wxMouseEvent &event);

    void Solve();

    /**
     * Stop the timer so the window can close
     */
    void Stop() {mTimer.Stop();}

};

#endif ACTIONSUDOKU_SUDOKULIB_GAMEVIEW_H
