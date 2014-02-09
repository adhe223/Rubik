#include "Solver.h"
#include <iostream>
using namespace std;

Solver::Solver() {
	currentNode = new Node();
	distance = 0;
	cutoff = currentNode->getHeurScore();

	ida_star(currentNode);
}

void Solver::ida_star(Node * inNode) {
	inNode->setDiscovered(true);
	cout << "Working" << endl;

	if (inNode->isSolved()) {
		cout << "Congratulations! The cube has been solved!: " << endl;
		inNode->getCube()->printCube();
		return;
	}
	else if (inNode->getCheapestNode()->getHeurScore() > inNode->getHeurScore()) {
		cout << "Pruned this tree" << endl;
		return ida_star(inNode->getRoot());
	}

	return ida_star(inNode->getCheapestNode());
}