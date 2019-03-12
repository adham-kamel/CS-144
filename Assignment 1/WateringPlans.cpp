#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*** Complete this program. ***/

int main()
{
    const int UNITS_PER_CAN = 3;
    const string INPUT_FILE_NAME = "counts.txt";
    int plant_count;

    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Loop once for each number of plants read from the input file.
    // Stop when the number of plants is 0 or less.
    // During each loop, simulate Plan Near and Plan Far.
    do
    {
        input >> plant_count;
        // if input is <= 0 break out of for loop
		if (plant_count <= 0) {
			break;
		}

		// Plan Near
		int near_steps = 0;
		int near_cum_units = 0;
		int near_water_amt = UNITS_PER_CAN;

		cout << endl;
		cout << "==========================" << endl;
		cout << " Plan Near with " << plant_count << " plants" << endl;
		cout << "==========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl; // 15 27 42
		/*** Complete the code for Plan Near. ***/
		for (int plant_iter = 1; plant_iter <= plant_count; plant_iter++) {
			// no more water in the can
			if (near_water_amt == 0) {
				near_steps += plant_iter - 1;
				cout << "FAUCET         " << near_steps << "           " << near_water_amt << "              " << near_cum_units << endl;
				near_water_amt = UNITS_PER_CAN;
			}
			// water can is filled
			if (near_water_amt == UNITS_PER_CAN) {
				near_cum_units += plant_iter * near_water_amt;
				near_steps += plant_iter;
				cout << "Plant " << plant_iter << "        " << near_steps << "           " << near_water_amt << "              " << near_cum_units << endl;
			}
			else {
				near_cum_units += near_water_amt;
				near_steps++;
				cout << "Plant " << plant_iter << "        " << near_steps << "           " << near_water_amt << "              " << near_cum_units << endl;
			}
			near_water_amt--;
			// last plant has been watered return to faucet
			if (plant_iter == plant_count) {
				near_steps += plant_iter;
				near_cum_units += plant_iter * near_water_amt;
				cout << "FAUCET         " << near_steps << "           " << near_water_amt << "              " << near_cum_units << endl;
			}
		}
		cout << endl;
		cout << "Plan Near: Total steps = " << near_steps << ", total step-units = " << near_cum_units << endl;

		// Plan Far
		int far_steps = 0;
		int far_cum_units = 0;
		int far_water_amt = UNITS_PER_CAN;

		cout << endl;
		cout << "=========================" << endl;
		cout << " Plan Far with " << plant_count << " plants" << endl;
		cout << "=========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl;

		/*** Complete the code for Plan Far. ***/
		for (int plant_iter = plant_count; plant_iter >= 1; plant_iter--) {
			// no more water in can
			if (far_water_amt == 0) {
				far_steps += plant_iter + 1;
				cout << "FAUCET         " << far_steps << "           " << far_water_amt << "              " << far_cum_units << endl;
				far_water_amt = UNITS_PER_CAN;
			}
			// water can is filled
			if (far_water_amt == UNITS_PER_CAN) {
				far_cum_units += plant_iter * far_water_amt;
				far_steps += plant_iter;
				cout << "Plant " << plant_iter << "        " << far_steps << "           " << far_water_amt << "              " << far_cum_units << endl;
			}
			else {
				far_cum_units += far_water_amt;
				far_steps++;
				cout << "Plant " << plant_iter << "        " << far_steps << "           " << far_water_amt << "              " << far_cum_units << endl;
			}
			far_water_amt--;
			// last plant has been watered return to faucet
			if (plant_iter == 1) {
				far_steps += plant_iter;
				far_cum_units += plant_iter * far_water_amt;
				cout << "FAUCET         " << far_steps << "           " << far_water_amt << "              " << far_cum_units << endl;
			}
		}
		cout << endl;
		cout << "Plan Far: Total steps = " << far_steps << ", total step-units = " << far_cum_units << endl;

		// Which plan is better? Better means fewer step-units.
		cout << endl;
		cout << "*** With " << plant_count << " plants, ";
		// Near is better
		if (near_cum_units < far_cum_units) {
			cout << "Plan Near is better with " << far_cum_units - near_cum_units << " fewer step-units." << endl;
		}
		// Far is better
		else if (far_cum_units < near_cum_units) {
			cout << "Plan Far is better with " << near_cum_units - far_cum_units << " fewer step-units." << endl;
		}
		// Both are equal
		else {
			cout << "Both plans are equal." << endl;
		}
	} while (plant_count > 0);

	return 0;
}
