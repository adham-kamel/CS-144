#include <math.h>
#include "Node.h"
#include <iomanip>
/***** Complete this class. *****/

Node::Node(Coordinate coordinate) {
	convert_coordinate(coordinate);
	next = nullptr;
}

Node::Node(City city){
	name = city.name;
	state = city.state;
	convert_coordinate(city.coordinate);
	next = nullptr;
}

void Node::convert_coordinate(Coordinate& coordinate) {
	row = round(2 * (Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
	col = round(2 * (coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

int Node::getRow() {
	return row;
}

int Node::getCol() {
	return col;
}

string Node::getName(){
	return name;
}

string Node::getState(){
	return state;
}



