#include "Node.h"

Node::Node() {
	root = NULL;
	cube = new Cube();
	cube->shuffleCube(2);
	//cube->frontCounter();
	distanceTo = 0;
	discovered = false;

	heurScore = cube->heuristicGuess();
	totalScore = distanceTo + heurScore;

	//Initialize Successors
	for (int i = 0; i < 12; i++) {
		successors[i] = NULL;
	}
}

Node::Node(Node * inRoot, Cube * inCube, int inDistance) {
	root = inRoot;
	cube = inCube;
	distanceTo = inDistance;
	discovered = false;

	heurScore = cube->heuristicGuess();
	totalScore = distanceTo + heurScore;

	//Initialize Successors
	for (int i = 0; i < 12; i++) {
		successors[i] = NULL;
	}
}

Node::Node(const Node & inNode) {
	root = NULL;
	cube = new Cube(*inNode.getCube());
	distanceTo = 0;
	discovered = false;

	heurScore = cube->heuristicGuess();
	totalScore = distanceTo + heurScore;

	//Initialize Successors
	for (int i = 0; i < 12; i++) {
		successors[i] = NULL;
	}
}

float Node::getTotalScore() {
	return totalScore;
}

float Node::getHeurScore() {
	return heurScore;
}

Cube * Node::getCube() const {
	return cube;
}

Node * Node::getRoot() {
	return root;
}

bool Node::isSolved() {
	return cube->isSolved();
}

int Node::getDistanceTo() {
	return distanceTo;
}

bool Node::getDiscovered() {
	return discovered;
}

void Node::setDiscovered(bool b) {
	discovered = b;
}
