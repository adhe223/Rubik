#ifndef NODE_H
#define NODE_H
#include "Cube.h"

class Node {
public:
	Node();
	Node(Node * inRoot, Cube * inCube, int inDistance);
	Node(const Node & inNode);

	float getTotalScore() const;
	float getHeurScore() const;
	Cube * getCube() const;
	bool isSolved();

	int getDistanceTo() const;
	bool getDiscovered() const;
	void setDiscovered(bool b);

	Node * getRoot() const;

	//public member variable for ease of access
	Node * successors[12];

private:
	bool discovered;
	int distanceTo;
	Cube * cube;
	Node * root;
};

#endif