#include "RPSGame.h"
#include "GameFrame.h"

// Create a new application object.
wxIMPLEMENT_APP(RPSGame);

bool RPSGame::OnInit()
{
    if (!wxApp::OnInit()) return false;

    DemoFrame *frame = new DemoFrame("Rock Paper Scissors");
    frame->Show(true);

    return true;
}
