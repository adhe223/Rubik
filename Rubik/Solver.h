#ifndef SOLVER_H
#define SOLVER_H

#include "Node.h"
#include <vector>

class Solver{
public:
	Solver();
	//void ida_star(Node * inNode);
	//Node * getCheapestChild(Node * inNode);

	void depthFirstSearch(Node * root);
	void IDFS(Node * root);


private:
	bool find(int n, std::vector<int> vectInts);

	Node * currentNode;
	int distanceTo;
	double calls;
	float minFail;
	Node * solved;
	float bound;
};

#endif