#include "Node.h"

Node::Node() {
	root = NULL;
	cube = new Cube();
	cube->shuffleCube(1000);
	distanceTo = 0;
	discovered = false;

	heurScore = cube->heuristicGuess();
	totalScore = distanceTo + heurScore;
	
	//Calculate the scores of all the possible paths
	//frontClock
	Cube * alteredCube0 = new Cube(*cube);
	alteredCube0->frontClock();
	possMoves[0] = new Node(this, alteredCube0, distanceTo);

	//frontCounter
	Cube * alteredCube1 = new Cube(*cube);
	alteredCube1->frontCounter();
	possMoves[1] = new Node(this, alteredCube1, distanceTo);

	//leftClock
	Cube * alteredCube2 = new Cube(*cube);
	alteredCube2->leftClock();
	possMoves[2] = new Node(this, alteredCube2, distanceTo);

	//leftCounter
	Cube * alteredCube3 = new Cube(*cube);
	alteredCube3->leftCounter();
	possMoves[3] = new Node(this, alteredCube3, distanceTo);

	//topClock
	Cube * alteredCube4 = new Cube(*cube);
	alteredCube4->topClock();
	possMoves[4] = new Node(this, alteredCube4, distanceTo);

	//topCounter
	Cube * alteredCube5 = new Cube(*cube);
	alteredCube5->topCounter();
	possMoves[5] = new Node(this, alteredCube5, distanceTo);

	//rightClock
	Cube * alteredCube6 = new Cube(*cube);
	alteredCube6->rightClock();
	possMoves[6] = new Node(this, alteredCube6, distanceTo);

	//rightCounter
	Cube * alteredCube7 = new Cube(*cube);
	alteredCube7->rightCounter();
	possMoves[7] = new Node(this, alteredCube7, distanceTo);

	//bottomClock
	Cube * alteredCube8 = new Cube(*cube);
	alteredCube8->bottomClock();
	possMoves[8] = new Node(this, alteredCube8, distanceTo);

	//bottomCounter
	Cube * alteredCube9 = new Cube(*cube);
	alteredCube9->bottomCounter();
	possMoves[9] = new Node(this, alteredCube9, distanceTo);

	//backClock
	Cube * alteredCube10 = new Cube(*cube);
	alteredCube10->backClock();
	possMoves[10] = new Node(this, alteredCube10, distanceTo);

	//backCounter
	Cube * alteredCube11 = new Cube(*cube);
	alteredCube11->backCounter();
	possMoves[11] = new Node(this, alteredCube11, distanceTo);
}

Node::Node(Node * inRoot, Cube * inCube, int inDistance) {
	root = inRoot;
	cube = inCube;
	distanceTo = inDistance + 1;
	discovered = false;

	heurScore = cube->heuristicGuess();
	totalScore = distanceTo + heurScore;
	
	//Calculate the scores of all the possible paths
	//frontClock
	Cube * alteredCube0 = new Cube(*cube);
	alteredCube0->frontClock();
	possMoves[0] = new Node(this, alteredCube0, distanceTo);

	//frontCounter
	Cube * alteredCube1 = new Cube(*cube);
	alteredCube1->frontCounter();
	possMoves[1] = new Node(this, alteredCube1, distanceTo);

	//leftClock
	Cube * alteredCube2 = new Cube(*cube);
	alteredCube2->leftClock();
	possMoves[2] = new Node(this, alteredCube2, distanceTo);

	//leftCounter
	Cube * alteredCube3 = new Cube(*cube);
	alteredCube3->leftCounter();
	possMoves[3] = new Node(this, alteredCube3, distanceTo);

	//topClock
	Cube * alteredCube4 = new Cube(*cube);
	alteredCube4->topClock();
	possMoves[4] = new Node(this, alteredCube4, distanceTo);

	//topCounter
	Cube * alteredCube5 = new Cube(*cube);
	alteredCube5->topCounter();
	possMoves[5] = new Node(this, alteredCube5, distanceTo);

	//rightClock
	Cube * alteredCube6 = new Cube(*cube);
	alteredCube6->rightClock();
	possMoves[6] = new Node(this, alteredCube6, distanceTo);

	//rightCounter
	Cube * alteredCube7 = new Cube(*cube);
	alteredCube7->rightCounter();
	possMoves[7] = new Node(this, alteredCube7, distanceTo);

	//bottomClock
	Cube * alteredCube8 = new Cube(*cube);
	alteredCube8->bottomClock();
	possMoves[8] = new Node(this, alteredCube8, distanceTo);

	//bottomCounter
	Cube * alteredCube9 = new Cube(*cube);
	alteredCube9->bottomCounter();
	possMoves[9] = new Node(this, alteredCube9, distanceTo);

	//backClock
	Cube * alteredCube10 = new Cube(*cube);
	alteredCube10->backClock();
	possMoves[10] = new Node(this, alteredCube10, distanceTo);

	//backCounter
	Cube * alteredCube11 = new Cube(*cube);
	alteredCube11->backCounter();
	possMoves[11] = new Node(this, alteredCube11, distanceTo);
}

float Node::getTotalScore() {
	return totalScore;
}

float Node::getHeurScore() {
	return heurScore;
}

Cube * Node::getCube() {
	return cube;
}

Node * Node::getRoot() {
	return root;
}

Node * Node::getCheapestNode() {
	float minIndex = -1;
	float minNumber = 10000000;
	for (int i = 0; i < 12; i++) {
		if (possMoves[i]->getHeurScore() < minNumber && possMoves[i]->getDiscovered() == false) { 
			minNumber = possMoves[i]->getHeurScore();
			minIndex = i;
		}
	}

	if (minIndex == 0) {
		return possMoves[0];
	} 
	else if(minIndex == 1) {
		return possMoves[1];
	}
	else if (minIndex == 2) {
		return possMoves[2];
	}
	else if (minIndex == 3) {
		return possMoves[3];
	}
	else if (minIndex == 4) {
		return possMoves[4];
	}
	else if (minIndex == 5) {
		return possMoves[5];
	}
	else if (minIndex == 6) {
		return possMoves[6];
	}
	else if (minIndex == 7) {
		return possMoves[7];
	}
	else if (minIndex == 8) {
		return possMoves[8];
	}
	else if (minIndex == 9) {
		return possMoves[9];
	}
	else if (minIndex == 10) {
		return possMoves[10];
	}
	else if (minIndex == 11) {
		return possMoves[11];
	}
	else {		//Min index is still -1, return root as all children have been discovered
		return root;
	}
}

bool Node::isSolved() {
	return cube->isSolved();
}

bool Node::getDiscovered() {
	return discovered;
}

void Node::setDiscovered(bool b) {
	discovered = b;
}

Node * Node::getFrontClock() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->frontClock();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getFrontCounter() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->frontCounter();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getLeftClock() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->leftClock();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getLeftCounter() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->leftCounter();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getTopClock() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->topClock();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getTopCounter() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->topCounter();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getRightClock() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->rightClock();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getRightCounter() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->rightCounter();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getBottomClock() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->bottomClock();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getBottomCounter() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->bottomCounter();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getBackClock() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->backClock();
	return new Node(this, alteredCube, distanceTo);
}

Node * Node::getBackCounter() {
	Cube * alteredCube = new Cube(*cube);
	alteredCube->backCounter();
	return new Node(this, alteredCube, distanceTo);
}
