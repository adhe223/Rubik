#include "Solver.h"
#include <iostream>
using namespace std;

Solver::Solver() {
	calls = 0;
	currentNode = new Node();
	distanceTo = 0;
	minFail = 1000000;
	//cutoff = currentNode->getHeurScore();

	//ida_star(currentNode);
	//depthFirstSearch(currentNode, 2);
	IDFS(currentNode);
}

void Solver::ida_star(Node * inNode) {
	calls++;
	currentNode = inNode;
	distanceTo = currentNode->getDistanceTo();
	currentNode->setDiscovered(true);
	cout << "Working on call " << calls << endl;

	Node * cheapestChild = getCheapestChild(inNode);
	if (cheapestChild == NULL) {	//This means that all the successors have been discovered already
		return ida_star(currentNode->getRoot());
	}

	if (currentNode->isSolved()) {
		cout << "Congratulations! The cube has been solved!: " << endl;
		currentNode->getCube()->printCube();
		return;
	}
	else if (cheapestChild->getHeurScore() > currentNode->getHeurScore()) {
		cout << "Pruned this tree" << endl;

		if (currentNode->getRoot() == NULL) {
			cout << "The puzzle is unsolveable!" << endl;
			return;
		}

		return ida_star(currentNode->getRoot());
	}

	return ida_star(cheapestChild);
}

float Solver::depthFirstSearch(Node * root, float bound) {
	//cutoff = bound;
	distanceTo = root->getDistanceTo();
	calls++;
	cout << "Working on call " << calls << endl;
	root->setDiscovered(true);

	if (root->isSolved()) {
		cout << "Congrats!" << endl;
		solved = root;
		return 0;
	}

	//Fill the successor nodes
	//frontClock
	if (root->successors[0] == NULL)
	{
		root->successors[0] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[0]->getCube()->frontClock();
	}

	//frontCounter
	if (root->successors[1] == NULL)
	{
		root->successors[1] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[1]->getCube()->frontCounter();
	}

	//leftClock
	if (root->successors[2] == NULL)
	{
		root->successors[2] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[2]->getCube()->leftClock();
	}

	//leftCounter
	if (root->successors[3] == NULL) {
		root->successors[3] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[3]->getCube()->leftCounter();
	}

	//topClock
	if (root->successors[4] == NULL) {
		root->successors[4] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[4]->getCube()->topClock();
	}

	//topCounter
	if (root->successors[5] == NULL) {
		root->successors[5] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[5]->getCube()->topCounter();
	}

	//rightClock
	if (root->successors[6] == NULL) {
		root->successors[6] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[6]->getCube()->rightClock();
	}

	//rightCounter
	if (root->successors[7] == NULL) {
		root->successors[7] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[7]->getCube()->rightCounter();
	}

	//bottomClock
	if (root->successors[8] == NULL) {
		root->successors[8] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[8]->getCube()->bottomClock();
	}

	//bottomCounter
	if (root->successors[9] == NULL) {
		root->successors[9] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[9]->getCube()->bottomCounter();
	}

	//backClock
	if (root->successors[10] == NULL) {
		root->successors[10] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[10]->getCube()->backClock();
	}

	//backCounter
	if (root->successors[11] == NULL) {
		root->successors[11] = new Node(root, new Cube(*root->getCube()), distanceTo + 1);
		root->successors[11]->getCube()->backCounter();
	}

	for (int i = 0; i < 12; i++) {
		if (root->successors[i]->getDiscovered() == false && root->successors[i]->getTotalScore() <= bound) {
			if (solved != NULL) { return 0; }
			depthFirstSearch(root->successors[i], bound);
		}
		else {
			//All do not meet the boundary. Find the min that doesn't meet the boundary requirement
			if (root->successors[i]->getTotalScore() < minFail) {
				minFail = root->successors[i]->getTotalScore();
			}
		}
	}
	//What if All the children nodes have been visited without a solution being found?
	

	return minFail;
}

void Solver::IDFS(Node * root) {
	Node * origRoot = new Node(*root);
	float bound = root->getTotalScore();

	//for (int i = 1; i < 3; i++) {
	while (true) {
		Node * toWorkOn = new Node(*origRoot);
		bound = depthFirstSearch(toWorkOn, bound);
		if (solved != NULL) {
			cout << "IDFS has solved the cube!" << endl;
			solved->getCube()->printCube();
			return;
		}
		cout << "Bound of is too small, increasing to " << bound << " need check more nodes!" << endl;
	}
}

Node * Solver::getCheapestChild(Node * inNode) {
	//Create the possible moves if the node doesn't already have them
	//frontClock
	if (currentNode->successors[0] == NULL)
	{
		currentNode->successors[0] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[0]->getCube()->frontClock();
	}

	//frontCounter
	if (currentNode->successors[1] == NULL)
	{
		currentNode->successors[1] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[1]->getCube()->frontCounter();
	}

	//leftClock
	if (currentNode->successors[2] == NULL)
	{
		currentNode->successors[2] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[2]->getCube()->leftClock();
	}

	//leftCounter
	if (currentNode->successors[3] == NULL) {
		currentNode->successors[3] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[3]->getCube()->leftCounter();
	}

	//topClock
	if (currentNode->successors[4] == NULL) {
		currentNode->successors[4] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[4]->getCube()->topClock();
	}

	//topCounter
	if (currentNode->successors[5] == NULL) {
		currentNode->successors[5] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[5]->getCube()->topCounter();
	}

	//rightClock
	if (currentNode->successors[6] == NULL) {
		currentNode->successors[6] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[6]->getCube()->rightClock();
	}

	//rightCounter
	if (currentNode->successors[7] == NULL) {
		currentNode->successors[7] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[7]->getCube()->rightCounter();
	}

	//bottomClock
	if (currentNode->successors[8] == NULL) {
		currentNode->successors[8] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[8]->getCube()->bottomClock();
	}

	//bottomCounter
	if (currentNode->successors[9] == NULL) {
		currentNode->successors[9] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[9]->getCube()->bottomCounter();
	}

	//backClock
	if (currentNode->successors[10] == NULL) {
		currentNode->successors[10] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[10]->getCube()->backClock();
	}

	//backCounter
	if (currentNode->successors[11] == NULL) {
		currentNode->successors[11] = new Node(currentNode, new Cube(*inNode->getCube()), distanceTo + 1);
		currentNode->successors[11]->getCube()->backCounter();
	}

	//Now find the cheapest move amongst the moves and take it if it is not discovered
	float minIndex = -1;
	float minNumber = 10000000;
	for (int i = 0; i < 12; i++) {
		if (currentNode->successors[i]->getHeurScore() < minNumber && currentNode->successors[i]->getDiscovered() == false) {
			minNumber = currentNode->successors[i]->getHeurScore();
			minIndex = i;
		}
	}

	if (minIndex == 0) {
		return currentNode->successors[0];
	}
	else if (minIndex == 1) {
		return currentNode->successors[1];
	}
	else if (minIndex == 2) {
		return currentNode->successors[2];
	}
	else if (minIndex == 3) {
		return currentNode->successors[3];
	}
	else if (minIndex == 4) {
		return currentNode->successors[4];
	}
	else if (minIndex == 5) {
		return currentNode->successors[5];
	}
	else if (minIndex == 6) {
		return currentNode->successors[6];
	}
	else if (minIndex == 7) {
		return currentNode->successors[7];
	}
	else if (minIndex == 8) {
		return currentNode->successors[8];
	}
	else if (minIndex == 9) {
		return currentNode->successors[9];
	}
	else if (minIndex == 10) {
		return currentNode->successors[10];
	}
	else if (minIndex == 11) {
		return currentNode->successors[11];
	}
	else {		//Min index is still -1, return NULL as all children have been discovered
		return NULL;
	}
}