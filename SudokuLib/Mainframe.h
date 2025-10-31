/**
 * @file Mainframe.h
 * @author Keerthi Vardhan
 *
 * The top-level frame of the application
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_MAINFRAME_H
#define ACTIONSUDOKU_SUDOKULIB_MAINFRAME_H

#include <wx/filehistory.h>
#include <wx/config.h>

class GameView;


/**
 * The top-level frame of the application
 */
class Mainframe : public wxFrame
{
private:
    /// View class for the game
    GameView* mGameView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);

public:

    void Initialize();

    void OpenLZero(wxCommandEvent& event);
    void OpenLOne(wxCommandEvent& event);
    void OpenLTwo(wxCommandEvent& event);
    void OpenLThree(wxCommandEvent& event);

    void Solve(wxCommandEvent& event);


};

#endif ACTIONSUDOKU_SUDOKULIB_MAINFRAME_H
