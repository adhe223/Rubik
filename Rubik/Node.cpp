#include "Node.h"

Node::Node() {
	root = NULL;
	cube = new Cube();
	cube->shuffleCube(6);
	distanceTo = 0;
	discovered = false;

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

	//Initialize Successors
	for (int i = 0; i < 12; i++) {
		successors[i] = NULL;
	}
}

Node::Node(const Node & inNode) {
	root = inNode.getRoot();
	cube = new Cube(*inNode.getCube());
	distanceTo = inNode.getDistanceTo();
	discovered = inNode.getDiscovered();

	//Initialize Successors
	for (int i = 0; i < 12; i++) {
		successors[i] = NULL;
	}
}

float Node::getTotalScore() const {
	return distanceTo + cube->heuristicGuess();
}

float Node::getHeurScore() const {
	return cube->heuristicGuess();
}

Cube * Node::getCube() const {
	return cube;
}

Node * Node::getRoot() const{
	return root;
}

bool Node::isSolved() {
	return cube->isSolved();
}

int Node::getDistanceTo() const {
	return distanceTo;
}

bool Node::getDiscovered() const {
	return discovered;
}

void Node::setDiscovered(bool b) {
	discovered = b;
}
