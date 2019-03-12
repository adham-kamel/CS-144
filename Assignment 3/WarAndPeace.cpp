/*
 * WarAndPeace.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: mbrogan13
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void findTheDarndedName();

// Names to search for.
const string ALEXEEVICH  = "Makar Alexeevich";
const string BAZDEEV     = "Joseph Bazdeev";
const string DRUBETSKOY  = "Boris Drubetskoy";
vector<string> theFile;

const string INPUT_FILE_NAME = "WarAndPeace.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // While loop to add the entire file to a vector
    while (!input.eof())
    {
    	string currentLine = "";
    	getline(input, currentLine);
    	theFile.push_back(currentLine);
    }

    // Prints the header and formatting for the LINE NUMBER, POSITION, and NAME
    cout << setw(5) << "LINE" << setw(10) << "POSITION" << " " << "NAME" << endl;

    // Call to the function
    findTheDarndedName();

    return 0;
}

/*
 * Method to find the names given for the assignments
 * @params N/A
 * @return N/A
 */
void findTheDarndedName()
{
	// Current line we're checking in the array
	int currentLineIndex = 1;

	// While loop to iterate through the whole vector (rip linear time)
	while (currentLineIndex != theFile.size() - 1)
	    {
			if ((currentLineIndex + 1) == 19361 || (currentLineIndex + 1) == 41166)
			{
				currentLineIndex++;
			}

			// Checking for Alexeevich's name in the current index of the vector
			// Checks for the whole name as well as the first and last name split against two lines
	    	size_t AlexNameFound = theFile.at(currentLineIndex).find(ALEXEEVICH);
	    	size_t AFirstName = theFile.at(currentLineIndex).find("Makar");
	    	size_t ALastName = theFile.at(currentLineIndex + 1).find("Alexeevich");

	    	// Checking for Badzeev's name in the current index of the vector
	    	// Checks for the whole name as well as the first and last name split against two lines
	    	size_t BazdeevNameFound = theFile.at(currentLineIndex).find(BAZDEEV);
	    	size_t BFirstName = theFile.at(currentLineIndex).find("Joseph");
	    	size_t BLastName = theFile.at(currentLineIndex + 1).find("Bazdeev");

	    	// Checking for Drubetskoy's name in the current index of the vector
	    	// Checks for the whole name as well as the first and last name split against two lines
	    	size_t DrubNameFound = theFile.at(currentLineIndex).find(DRUBETSKOY);
	    	size_t DFirstName = theFile.at(currentLineIndex).find("Boris");
	    	size_t DLastName = theFile.at(currentLineIndex + 1).find("Drubetskoy");

	    	// If the whole name was found, print the line position and name
	    	if (AlexNameFound != string::npos)
	    	{
	    		cout << currentLineIndex + 1 << setw(10) << AlexNameFound + 1 << " " << ALEXEEVICH << endl;
	    	}

	    	// If the name was split, print line position and name in relation to the first line
	    	else if ((AFirstName != string::npos) && (ALastName != string::npos))
	    	{
	    		cout << currentLineIndex + 1 << setw(10) << AFirstName + 1 << " " << ALEXEEVICH << endl;
	    	}

	    	// If the whole name was found, print the line position and name
	    	if (BazdeevNameFound != string::npos)
	    	{
	    		cout << currentLineIndex + 1 << setw(10) << BazdeevNameFound + 1 << " " << BAZDEEV << endl;
	    	}

	    	// If the name was split, print line position and name in relation to the first line
	    	else if ((BFirstName != string::npos) && (BLastName != string::npos))
	    	{
	    		cout << currentLineIndex + 1 << setw(10) << BFirstName + 1 << " " << BAZDEEV << endl;
	    	}

	    	// If the whole name was found, print the line position and name
	    	if (DrubNameFound != string::npos)
	    	{
	    		cout << currentLineIndex + 1 << setw(10) << DrubNameFound + 1 << " " << DRUBETSKOY << endl;
	    	}

	    	// If the name was split, print line position and name in relation to the first line
	    	else if ((DFirstName != string::npos) && (DLastName != string::npos))
	    	{
	    		cout << currentLineIndex + 1 << setw(10) << DFirstName + 1 << " " << DRUBETSKOY << endl;
	    	}

	    	currentLineIndex++; // increment the line index for the while loop
	    }
}

