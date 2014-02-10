#ifndef SOLVER_H
#define SOLVER_H

#include "Node.h"

class Solver{
public:
	Solver();
	void ida_star(Node * inNode);
	Node * getCheapestChild(Node * inNode);

	void depthFirstSearch(Node * root, float bound);
	void IDFS(Node * root);

	private:
	Node * currentNode;
	int distanceTo;
	float cutoff;
	double calls;
	Node * solved;
};

#endif