#ifndef NODE_H
#define NODE_H
#include "Cube.h"

class Node {
public:
	Node();
	Node(Node * inRoot, Cube * inCube, int inDistance);
	Node(const Node & inNode);

	float getTotalScore();
	float getHeurScore();
	Cube * getCube() const;
	bool isSolved();

	int getDistanceTo();
	bool getDiscovered();
	void setDiscovered(bool b);

	Node * getRoot();

	//public member variable for ease of access
	Node * successors[12];

private:
	bool discovered;
	int distanceTo;
	float totalScore;
	float heurScore;
	Cube * cube;
	Node * root;
};

#endif