// Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>

/***** Complete this program. *****/

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

// methods
void simulate(int);
Door hideCar();
Door openFirstDoor();
Door makeFirstChoice();
Door openSecondDoor();

// variables
Door hiddenCar;
Door firstChoice;
Door firstDoor;
Door secondDoor;
double firstWin = 0;
double secondWin = 0;

int main()
{
	// Run the simulations.
	srand(time(NULL));
	for (int i = 1; i <= SIMULATION_COUNT; i++) {
		simulate(i);
	}
	cout << endl;
	cout << firstWin << " wins if stay with the first choice" << endl;
	cout << secondWin << " wins if switched to the second choice" << endl;
	cout << "Win ratio of switch over stay: " << setprecision(2) << (secondWin / firstWin) << endl;
}

void simulate(int i) {
	cout << "#" << i;
	cout << " Hidden Car: " << hideCar();
	cout << " First Choice: " << makeFirstChoice();
	cout << " First Door Opened: " << openFirstDoor();
	cout << " Second Door Opened: " << openSecondDoor();
	if (hiddenCar == firstChoice) {
		cout << " Win First" << endl;
		firstWin++;
	}
	else if (hiddenCar == secondDoor) {
		cout << " Win Second" << endl;
		secondWin++;
	}
}

Door hideCar() {
	
	hiddenCar = rand() % 3 + 1;
	return hiddenCar;
}

Door makeFirstChoice() {
	firstChoice = rand() % 3 + 1;
	return firstChoice;
}

Door openFirstDoor() {
	firstDoor = rand() % 3 + 1;
	if (firstChoice == hiddenCar) {
		while (firstDoor == firstChoice) {
			firstDoor = rand() % 3 + 1;
		}
	}
	else {
		while (firstDoor == hiddenCar || firstDoor == firstChoice) {
			firstDoor = rand() % 3 + 1;
		}
	}
	return firstDoor;
}

Door openSecondDoor() {
	secondDoor = rand() % 3 + 1;
	while (secondDoor == firstDoor || secondDoor == firstChoice) {
		secondDoor = rand() % 3 + 1;
	}
	return secondDoor;
}
