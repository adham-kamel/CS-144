#include "ButtonPanel.h"
#include "wx/numdlg.h"

void ButtonPanel::init() {
	rounds = 0;
	human_win = 0;
	comp_win = 0;
	tie = 0;

	/*
	 * Asks how many rounds the player wants to play
	 */
	long res = wxGetNumberFromUser(
			wxT("Enter in amount of rounds you want to play"), wxT("Number:"),
			wxT("Number of Rounds"), 20, 1, 100, this);
	max_rounds = res;

	// Main sizer
	wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	/*
	 * Parts necessary to display the rounds of the game
	 */
	wxPanel *round_panel = new wxPanel(this, wxID_ANY);
	wxSizer *round_sizer = new wxGridSizer(3, 0, 5);

	wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY,
			"Round:");
	round_number_display = new wxStaticText(round_panel, wxID_ANY, "");
	round_number_display->SetFont(
			round_number_display->GetFont().Larger().Bold());
	round_text->SetFont(round_text->GetFont().Larger().Bold());
	round_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
	round_sizer->Add(round_number_display, 0, 0, 0);
	round_sizer->AddSpacer(5);
	round_panel->SetSizer(round_sizer);

	/*
	 * Parts necessary to display the title "Human" on the panel
	 */
	wxPanel *human_panel = new wxPanel(this, wxID_ANY);
	wxSizer *human_sizer = new wxGridSizer(2, 0, 5);

	wxStaticText *human_text = new wxStaticText(human_panel, wxID_ANY, "Human");
	human_text->SetFont(human_text->GetFont().Bold());
	human_sizer->Add(human_text);

	/*
	 * Parts necessary to display the button choices of Rock, Paper, and Scissors for the human to select
	 */
	wxPanel *button_panel = new wxPanel(this, wxID_ANY);
	wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
			"Choose:");
	wxButton *rock_button = new wxButton(button_panel, wxID_ANY,
			choice_to_wxString(ROCK));
	wxButton *paper_button = new wxButton(button_panel, wxID_ANY,
			choice_to_wxString(PAPER));
	wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
			choice_to_wxString(SCISSORS));

	rock_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_rock, this);
	paper_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_paper, this);
	scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

	button_sizer->Add(choose_text, 0, 0, 0);
	button_sizer->AddSpacer(5);
	button_sizer->Add(rock_button, 0, 0, 0);
	button_sizer->AddSpacer(5);
	button_sizer->Add(paper_button, 0, 0, 0);
	button_sizer->AddSpacer(5);
	button_sizer->Add(scissors_button, 0, 0, 0);
	button_panel->SetSizer(button_sizer);

	/*
	 * Parts necessary to display the selected human choice
	 */
	wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
	wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

	wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
			"Human Choice:");
	button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
	button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
	chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
	chosen_sizer->Add(button_chosen_text, 0, 0, 0);
	chosen_panel->SetSizer(chosen_sizer);

	/*
	 * Parts necessary to display the title "Computer" on the panel
	 */
	wxPanel *computer_panel = new wxPanel(this, wxID_ANY);
	wxSizer *computer_sizer = new wxGridSizer(2, 0, 5);

	wxStaticText *computer_text = new wxStaticText(computer_panel, wxID_ANY,
			"Computer");
	computer_text->SetFont(computer_text->GetFont().Bold());
	computer_sizer->Add(computer_text, 0, wxALIGN_RIGHT, 0);

	/*
	 * Parts necessary to display the randomly selected choice made by the comptuer
	 */
	wxPanel *computer_choice_panel = new wxPanel(this, wxID_ANY);
	wxSizer *computer_choice_sizer = new wxGridSizer(2, 0, 5);
	wxStaticText *computer_choice_text = new wxStaticText(computer_choice_panel,
			wxID_ANY, "Computer Random Choice:");
	computer_chosen_text = new wxStaticText(computer_choice_panel, wxID_ANY,
			"");
	computer_chosen_text->SetFont(computer_chosen_text->GetFont().Larger());
	computer_choice_sizer->Add(computer_choice_text, 0, wxALIGN_RIGHT, 0);
	computer_choice_sizer->Add(computer_chosen_text, 0, 0, 0);
	computer_choice_panel->SetSizer(computer_choice_sizer);

	/*
	 * Parts necessary to display the winner of the game
	 */
	wxPanel *winner_header = new wxPanel(this, wxID_ANY);
	wxSizer *winner_header_sizer = new wxGridSizer(3, 0, 5);
	wxStaticText *winner_header_text = new wxStaticText(winner_header, wxID_ANY,
			"The Winner:");
	winner_header_text->SetFont(winner_header_text->GetFont().Bold());
	winner_of_round = new wxStaticText(winner_header, wxID_ANY, "");
	winner_of_round->SetFont(winner_of_round->GetFont());
	winner_header_sizer->Add(winner_header_text, 0, wxALIGN_RIGHT, 0);
	winner_header_sizer->Add(winner_of_round, 0, 0, 0);
	winner_header->SetSizer(winner_header_sizer);

	/*
	 * Parts necessary to display the statistics of the overall match
	 */
	wxPanel *stats_panel = new wxPanel(this, wxID_ANY);
	wxPanel *stats_panel2 = new wxPanel(this, wxID_ANY);
	wxSizer *stats_sizer = new wxBoxSizer(wxVERTICAL);
	wxSizer *stats_sizer2 = new wxGridSizer(2, 0, 10);

	wxStaticText *stats_header_text = new wxStaticText(stats_panel, wxID_ANY,
			"Statistics");
	wxStaticText *stats_human_text = new wxStaticText(stats_panel2, wxID_ANY,
			"Human Wins:");
	wxStaticText *stats_computer_text = new wxStaticText(stats_panel2, wxID_ANY,
			"Computer Wins:");
	wxStaticText *stats_tietext = new wxStaticText(stats_panel2, wxID_ANY,
			"Ties:");
	human_wins = new wxStaticText(stats_panel2, wxID_ANY, "");
	comp_wins = new wxStaticText(stats_panel2, wxID_ANY, "");
	ties = new wxStaticText(stats_panel2, wxID_ANY, "");

	stats_sizer->Add(stats_header_text, 0, wxALIGN_CENTER, 0);
	stats_sizer2->Add(stats_human_text, 0, wxALIGN_RIGHT, 0);
	stats_sizer2->Add(human_wins, 0, 0, 0);
	stats_sizer2->Add(stats_computer_text, 0, wxALIGN_RIGHT, 0);
	stats_sizer2->Add(comp_wins, 0, 0, 0);
	stats_sizer2->Add(stats_tietext, 0, wxALIGN_RIGHT, 0);
	stats_sizer2->Add(ties, 0, 0, 0);
	stats_panel->SetSizer(stats_sizer);
	stats_panel2->SetSizer(stats_sizer2);

	/**
	 * Parts necessary to add the Reset Game button to the panel
	 */
	wxPanel *button_panel2 = new wxPanel(this, wxID_ANY);
	wxSizer *button_sizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxButton *reset_game = new wxButton(button_panel2, wxID_ANY, "Reset Game");

	reset_game->Bind(wxEVT_BUTTON, &ButtonPanel::on_reset, this);

	button_sizer2->Add(reset_game, 0, 0, 0);
	button_panel2->SetSizer(button_sizer2);

	/**
	 * Adding all the parts to make up the overall game panel
	 */
	sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(10);
	sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(20);
	sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(10);
	sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(20);
	sizer->Add(computer_panel, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(10);
	sizer->Add(computer_choice_panel, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(10);
	sizer->Add(winner_header, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(10);
	sizer->Add(stats_panel, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(5);
	sizer->Add(stats_panel2, 0, wxALIGN_CENTER, 0);
	sizer->AddSpacer(5);
	sizer->Add(button_panel2, 0, wxALIGN_CENTER, 0);

	SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event) {
	if (rounds < max_rounds) {
		human_choice = ROCK;
		comp_choice = computer_choice();
		update_button_choice_text(ROCK);
		update_computer_choice(comp_choice);
		winner(human_choice, comp_choice);
		rounds++;
		wxString roundnum = wxString::Format(wxT("%i"), rounds);
		update_round_number(roundnum);
	} else {
		update_round_number("Game Over");
	}
}

void ButtonPanel::on_paper(wxCommandEvent& event) {
	if (rounds < max_rounds) {
		human_choice = PAPER;
		comp_choice = computer_choice();
		update_button_choice_text(PAPER);
		update_computer_choice(comp_choice);
		winner(human_choice, comp_choice);
		rounds++;
		wxString roundnum = wxString::Format(wxT("%i"), rounds);
		update_round_number(roundnum);
	} else {
		update_round_number("Game Over");
	}
}

void ButtonPanel::on_scissors(wxCommandEvent& event) {
	if (rounds < max_rounds) {
		human_choice = SCISSORS;
		comp_choice = computer_choice();
		update_button_choice_text(SCISSORS);
		update_computer_choice(comp_choice);
		winner(human_choice, comp_choice);
		rounds++;
		wxString roundnum = wxString::Format(wxT("%i"), rounds);
		update_round_number(roundnum);
	} else {
		update_round_number("Game Over");
	}
}

void ButtonPanel::on_reset(wxCommandEvent& event) {
	rounds = 0;
	human_win = 0;
	comp_win = 0;
	tie = 0;
	update_round_number("");
	update_ties("");
	update_human_win("");
	update_comp_win("");
	max_rounds = wxGetNumberFromUser(wxT("Enter in amount of games"),
			wxT("Number:"), wxT("number please"), 20, 1, 100, this);
}


void ButtonPanel::update_button_choice_text(const Choice choice) {
	button_chosen_text->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_computer_choice(const Choice choice) {
	computer_chosen_text->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_round_number(wxString round) {
	round_number_display->SetLabelText(round);
}

void ButtonPanel::update_human_win(wxString number) {
	human_wins->SetLabelText(number);
}

void ButtonPanel::update_comp_win(wxString number) {
	comp_wins->SetLabelText(number);
}

void ButtonPanel::update_ties(wxString number) {
	ties->SetLabelText(number);
}

int ButtonPanel::rng() {
	return rand() % 3 + 1;
}

Choice ButtonPanel::computer_choice() {
	int rand_num = rng();
	if (rand_num == 1) {
		return ROCK;
	} else if (rand_num == 2) {
		return PAPER;
	}
	return SCISSORS;
}

void ButtonPanel::winner(const Choice human, const Choice comp) {
	if (human == comp) {
		winner_of_round->SetLabelText("Tie");
		tie++;
		wxString tiesnum = wxString::Format(wxT("%i"), tie);
		update_ties(tiesnum);
	} else if ((human == ROCK && comp == SCISSORS)
			|| (human == PAPER && comp == ROCK)
			|| (human == SCISSORS && comp == PAPER)) {
		winner_of_round->SetLabelText("Human");
		human_win++;
		wxString humannum = wxString::Format(wxT("%i"), human_win);
		update_human_win(humannum);
	} else if ((human == ROCK && comp == PAPER)
			|| (human == PAPER && comp == SCISSORS)
			|| (human == SCISSORS && comp == ROCK)) {
		winner_of_round->SetLabelText("Computer");
		comp_win++;
		wxString compnum = wxString::Format(wxT("%i"), comp_win);
		update_comp_win(compnum);
	}
}
