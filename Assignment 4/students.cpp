#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

typedef string *NamePtr; // typedef for the 1D array of names
typedef int *Scores; // typedef for columns of 2D array of scores
typedef Scores *RowScores; // typedef for rows of 2D array of scores

int make_arrays(ifstream&, NamePtr&, RowScores&); // finds the class name and class size and creates the dynamic arrays
int find_num_scores(ifstream&, NamePtr&, RowScores&, int); // finds the number of scores for each person, making the columns for the 2D array of scores
void print_scores(NamePtr&, RowScores&, int, int); // prints the scores

const string INPUT_FILE_NAME = "students.txt";

/**
 * Main.
 */
int main()
{
	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	/***** Complete this program. *****/
	NamePtr student_names = nullptr; // dynamic array for the names
	RowScores student_scores = nullptr; // 2D dynamic array for the scores for each student
	int class_size = make_arrays(input, student_names, student_scores); // the total size of the class
	for (int i = 0; i < class_size; i++) { // goes through each student
		int num_scores = find_num_scores(input, student_names, student_scores, i); // how many scores are inputted for each student
		print_scores(student_names, student_scores, i, num_scores);
	}
	delete[] student_names; // deletes the dynamic array for the names
	delete[] student_scores; // deletes the dynamic array for the scores
	return 0;
}

/*
This method finds the class name and class size from the input file as well as initialize the dynamic arrays
@param input - the reference for the input file
@param names - the reference for the dynamic array that holds the names
@param scores - the reference for the dynamic array that holds the scores
@return class_size - the total number of students in the class
*/
int make_arrays(ifstream& input, NamePtr& names, RowScores& scores) {
	string line;
	getline(input, line); // read the first line
	size_t space = line.find(" "); // separate class title and class size
	string class_name = line.substr(0, space); // name of the class
	int class_size = stoi(line.substr(space + 1, line.length())); // number of people in the class
	cout << "STUDENT SCORES for " << class_name << endl;
	cout << endl;

	names = new string[class_size]; // 1D dynamic array to hold the names of the students
	scores = new Scores[class_size]; // 2D dynamic array for the scores of each student
	return class_size;
}

/*
Finds the number of scores per student
@param input - the reference for the input file
@param names - the reference for the array of names of the students
@param scores - the reference for the array of scores per student
@param iterator - an specified iterator to check which student to access
@return num_scores - the number of scores per student
*/
int find_num_scores(ifstream& input, NamePtr& names, RowScores& scores, int iterator) {
	string line;
	int num_scores = 0; // total scores per student
	getline(input, line); // gets one line
	int space_count = 0; // number of spaces
	int space_name; // where the space is in the line
	int last_space; // where the previous space is in the line
	int score_count = 0; // number of scores added to the array
	for (int j = 0; j < line.length(); j ++) {
		int current = line[j]; // current character in line
		if (isspace(current)) {
			space_count++;
			if (space_count == 1) { // between first and last name
			}
			else if (space_count == 2) { // gets the full name
				space_name = j;
				last_space = j;
				names[iterator] = line.substr(0, space_name); // adds name to the array of names
			}
			else if (space_count == 3) { // space after the number of scores for an individual student
				last_space = j;
				num_scores = atoi(line.substr(space_name + 1, j).c_str()); // gets an int from the string of the number of scores
				scores[iterator] = new int[num_scores]; // creates the second dimension of the scores array
			}
			else if (space_count > 3) { // accesses each score per student
				scores[iterator][score_count] = atoi(line.substr(last_space + 1, j).c_str()); // adds a score to the array
				last_space = j;
				score_count++;
			}
		}
	}
	if (num_scores != 0) { // if there was a score so I could add the last score in the line
		scores[iterator][score_count] = atoi(line.substr(last_space, line.length()).c_str()); // adds last score to scores array
	}
	return num_scores;
}

/*
Prints the desired output from names and scores array
@param names - the reference to the array of student names
@param scores - the reference to the array of scores
@param iterator - a specified iterator to access info from each student
@param num_scores - the number of scores per student
*/
void print_scores(NamePtr& names, RowScores& scores, int iterator, int num_scores) {
	cout << names[iterator] << " " << endl;
	if (num_scores == 0) {
		cout << setw(9) << "(none)";
	}
	for (int j = 0; j < num_scores; j++) {
		cout << setw(5) << scores[iterator][j];
	}
	cout << endl;
	cout << endl;
}

