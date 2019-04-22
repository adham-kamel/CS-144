#ifndef BUTTONPANEL_H_
#define BUTTONPANEL_H_

#include "RPSGame.h"
#include "Choice.h"

/**
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:

	int rounds;
	int max_rounds;
	int human_win;
	int comp_win;
	int tie;
    /**
     * Constructor.
     * @param parent the parent frame.
     */
    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

    /**
     * Event handler for the rock button.
     * @param event the button click event.
     */
    void on_rock(wxCommandEvent& event);

    /**
     * Event handler for the paper button.
     * @param event the button click event.
     */
    void on_paper(wxCommandEvent& event);

    /**
     * Event handler for the scissors button.
     * @param event the button click event.
     */
    void on_scissors(wxCommandEvent& event);

    /**
     * Event handler for the reset game button
     * @param event the button click event
     */
    void on_reset(wxCommandEvent& event);

private:
    wxStaticText *button_chosen_text;
    wxStaticText *computer_chosen_text;
    wxStaticText *winner_of_round;
    wxStaticText *round_number_display;

    wxStaticText *human_wins;
    wxStaticText *comp_wins;
	wxStaticText *ties;

    Choice human_choice;
    Choice comp_choice;

    /**
     * Initialize the panel contents.
     */
    void init();

    /**
     * Update the displayed button choice object.
     * @param choice the chosen object.
     */
    void update_button_choice_text(const Choice choice);

    /**
     * Update the displayed choice for the computer
     * @param the random choice by the computer
     */
    void update_computer_choice(const Choice choice);

    /**
     * Update the round number
     * @param the round number
     */
    void update_round_number(wxString round);

    /**
     * Update the total human wins
     * @param the number of human wins
     */
    void update_human_win(wxString num);

    /**
     * Update the total computer wins
     * @param the number of comp wins
     */
    void update_comp_win(wxString num);

    /**
     * Update the total number of ties
     * @param the number of ties
     */
    void update_ties(wxString num);

    /**
     * Randomly pick a number between 1 and 3 to signify Rock Paper or Scissors
     * @return the random int
     */
    int rng();

    /**
     * Make a choice according to the random number through RNG()
     * @return the random choice
     */
    Choice computer_choice();

    /**
     * Determines who the winner of the round is
     * @param the human choice
     * @param the computer choice
     */
    void winner(const Choice human, const Choice comp);
};

#endif /* BUTTONPANEL_H_ */
