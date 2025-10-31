/**
 * @file SudokuApp.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"

#include "SudokuApp.h"
#include <Mainframe.h>

/**
 * Initialize the application.
 * @return
 */
bool SudokuApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new Mainframe();
    frame->Initialize();

    frame->SetFocus();
    frame->Raise();
    frame->Show(true);

    return true;
}
