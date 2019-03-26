#include "Coordinate.h"
#include <string.h>

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/***** Complete this class. *****/
Coordinate::Coordinate(){
   latitude = 0.0;
   longitude = 0.0;
}

//Constructor for Coordinates
Coordinate::Coordinate(double latitude_input, double longitude_input){
   latitude = latitude_input;
   longitude = longitude_input;
}



istream& operator >>(istream& ins, Coordinate& coordinate){
	string line;
	getline(ins, line, ',');
	coordinate.latitude = stod(line);
	getline(ins, line);
	coordinate.longitude = stod(line);
	return ins;
}

ostream& operator <<(ostream& outs, Coordinate& coordinate){
	outs << coordinate.latitude << "," << coordinate.longitude;
	return outs;
}

double Coordinate::get_latitude(){
	return latitude;
}

double  Coordinate::get_longitude(){
	return longitude;
}
