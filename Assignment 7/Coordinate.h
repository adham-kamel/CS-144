#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate {
public:

	/***** Commplete this class. *****/
	Coordinate();
	Coordinate(double latitude_input, double longitude_input);

	/**
	 * Overloaded input stream extraction operator
	 * to read a coordinate from an input stream.
	 * @param ins the input stream.
	 * @param coordinate the coordinate to read.
	 * @return the input stream.
	 */
	friend istream& operator >>(istream& ins, Coordinate& coordinate);

	/**
	 * Overloaded stream output insertion operator
	 * to output the entire sorted linked list.
	 * @param outs the output stream.
	 * @param list the sorted linked list to output.
	 * @return the output stream.
	 */
	friend ostream& operator <<(ostream& outs, Coordinate& coordinate);

	double get_latitude(); // get latitude of coordinate
	double get_longitude(); // get longitude of coordinate

	// Constants for this app's input data.
	static const double MAX_LATITUDE;
	static const double MIN_LONGITUDE;

private:
	double latitude;
	double longitude;
};

#endif /* COORDINATE_H_ */
