#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A node of a linked list.
 */
class Node {
public:

	/***** Complete this class. *****/

	Node *next;  // pointer to the next node in the list
	Node(Coordinate coordinate); // Node constructor from coordinate
	Node(City city); // Node constructor from city

	int getRow(); // gets row of node
	int getCol(); // gets col of node
	string getName(); // gets name of city
	string getState(); // gets state of city


	/**
	 * Overloaded > operator to compare two nodes.
	 */
	bool operator >(const Node& other) {
		if (row > other.row) {
			return true;
		}
		if (row == other.row && col > other.col) {
			return true;
		}
		return false;
	}

	/**
	 * Overloaded stream output insertion operator
	 * to output a node to the output stream.
	 * @param outs the output stream.
	 * @param node the node to output.
	 * @return the output stream.
	 */
	friend ostream& operator <<(ostream& outs, Node& node) {
		if (node.name == "") //Print the boundary
		      outs << "#";
		   else
		   {
		      City city(node.name, node.state); //Print the city
		      outs << "*" << city;
		   }

		   return outs;
	}

private:
	string name;   // city name,  or the empty string for a border location
	string state;  // city state, or the empty string for a border location
	int row;       // print row
	int col;       // print column

	/**
	 * Convert a coordinate to a row and a column.
	 * @param coordinate the coordinate to convert.
	 */
	void convert_coordinate(Coordinate& coordinate);
};

#endif /* NODE_H_ */
