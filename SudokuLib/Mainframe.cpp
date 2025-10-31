/**
 * @file Mainframe.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"
#include "ids.h"

#include "Mainframe.h"

#include "GameView.h"

/// Level Zero
const wxString levelZero = "levels/level0.xml";

/// Level One
const wxString levelOne = "levels/level1.xml";

/// Level Two
const wxString levelTwo = "levels/level2.xml";

/// Level Three?
const wxString levelThree = "levels/level3PotentialFeature.xml";

/**
 * Initialize the Mainframe window
 */
void Mainframe::Initialize()
{
    Create(nullptr, wxID_ANY, L"Action Sudoku", wxDefaultPosition,  wxSize( 1000,800 ));

    auto sizer = new wxBoxSizer( wxVERTICAL );

    mGameView = new GameView();
    mGameView->Initialize(this);

    sizer->Add(mGameView, 1, wxEXPAND | wxALL);

    SetSizer( sizer );
    Layout();

    CreateStatusBar();

    auto menuBar = new wxMenuBar();

    auto fileMenu = new wxMenu();
    auto levelMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    fileMenu->Append(IDM_SOLVE, "Solve", L"Solve the sudoku");
    fileMenu->Append(wxID_EXIT, "E&xit", L"Quit this program");

    levelMenu->Append(IDM_LEVEL_ZERO, "Level 0", "Start from level 0");
    levelMenu->Append(IDM_LEVEL_ONE, "Level 1", "Start from level 1");
    levelMenu->Append(IDM_LEVEL_TWO, "Level 2", "Start from level 2");
    levelMenu->Append(IDM_LEVEL_THREE, "Level 3", "Start from level 3");

    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");


    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &Mainframe::OnClose, this);

    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::OpenLZero, this, IDM_LEVEL_ZERO);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::OpenLOne, this, IDM_LEVEL_ONE);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::OpenLTwo, this, IDM_LEVEL_TWO);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::OpenLThree, this, IDM_LEVEL_THREE);

    Bind(wxEVT_COMMAND_MENU_SELECTED, &Mainframe::Solve, this, IDM_SOLVE);

    menuBar->Append(fileMenu, L"&File");
    menuBar->Append(levelMenu, L"&Levels");
    menuBar->Append(helpMenu, L"&Help");

    SetMenuBar( menuBar );

    mGameView->Load(1);

}

/**
 * Exit menu option handlers
 * @param event
 */
void Mainframe::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * Application about box menu handler
 */
void Mainframe::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(L"Action Sudoku!",
                 L"Action Sudoku",
                 wxOK | wxCENTRE,
                 this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void Mainframe::OnClose(wxCloseEvent& event)
{
    mGameView->Stop();
    Destroy();
}


/**
 * Open level zero
 * @param event
 */
void Mainframe::OpenLZero(wxCommandEvent &event)
{
    mGameView->Load(0);
}

/**
 * Open level one
 * @param event
 */
void Mainframe::OpenLOne(wxCommandEvent &event)
{
    mGameView->Load(1);
}

/**
 * Open level two
 * @param event
 */
void Mainframe::OpenLTwo(wxCommandEvent &event)
{
    mGameView->Load(2);
}

/**
 * Open level three
 * @param event
 */
void Mainframe::OpenLThree(wxCommandEvent &event)
{
    //mGameView->Load(levelThree);
}

/**
 * Event handler for solve
 * @param event
 */
void Mainframe::Solve(wxCommandEvent &event)
{
    mGameView->Solve();
}
