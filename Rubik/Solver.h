#ifndef SOLVER_H
#define SOLVER_H

#include "Node.h"

class Solver{
public:
	Solver();
	void ida_star(Node * inNode);
	Node * getCheapestChild(Node * inNode);

	float depthFirstSearch(Node * root);
	void IDFS(Node * root);

	private:
	Node * currentNode;
	int distanceTo;
	double calls;
	float minFail;
	Node * solved;
	float bound;
};

#endif