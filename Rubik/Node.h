#ifndef NODE_H
#define NODE_H
#include "Cube.h"

class Node {
public:
	Node();
	Node(Node * inRoot, Cube * inCube, int inDistance);

	float getTotalScore();
	float getHeurScore();
	Cube * getCube();
	Node * getCheapestNode();
	bool isSolved();

	bool getDiscovered();
	void setDiscovered(bool b);

	Node * getRoot();
	Node * getFrontClock();
	Node * getFrontCounter();
	Node * getLeftClock();
	Node * getLeftCounter();
	Node * getTopClock();
	Node * getTopCounter();
	Node * getRightClock();
	Node * getRightCounter();
	Node * getBottomClock();
	Node * getBottomCounter();
	Node * getBackClock();
	Node * getBackCounter();

private:
	bool discovered;
	int distanceTo;
	float totalScore;
	float heurScore;
	Cube * cube;

	Node * root;

	//Scores of the cubes of all possible moves
	Node * possMoves[11];
	/*Node * frontClock;
	Node * frontCounter;
	Node * leftClock;
	Node * leftCounter;
	Node * topClock;
	Node * topCounter;
	Node * rightClock;
	Node * rightCounter;
	Node * bottomClock;
	Node * bottomCounter;
	Node * backClock;
	Node * backCounter;*/
};

#endif