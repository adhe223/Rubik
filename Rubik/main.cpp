//Alex Henry
//CS463 Assign 1
//Due 1/30/14

#include "Cube.h"
#include "Solver.h"
#include <iostream>
#include <vector>
using namespace std;

//Helper function
bool find(int n, vector<int> vectInts) {
	bool found = false;
	for (int i = 0; i < vectInts.size(); i++) {
		if (vectInts[i] == n) {
			found = true;
		}
	}

	return found;
}

int main() {
	Solver * solver = new Solver();

	/*
	//Take in input from the user
	cout << "Input a string of length two. The first character specifies the face to manipulate and the second specifies the direction." << endl
		<< "For the face:" << endl << "f = front" << endl << "l = left" << endl << "r = right" << endl << "t = top" << endl << "b = bottom"
		<< endl << "a = back." << endl
		<< "For the direction (direction is specified as if you were looking at the face you are going to manipulate)." << endl
		<< "So if you are looking from the front, a back clockwise move looks counterclockwise." << endl
		<< "* = clockwise" << endl
		<< ", = counterclockwise" << endl << endl;
	bool quit = false;
	string move;
	while (!quit) {
		cout << "Input 'quit' if you'd like to quit." << endl;
		cout << "Please enter a move you'd like to execute (case senstive): ";
		cin >> move;
		if (move == "quit") { quit = true; }
		if (!quit) {
			cube->userRotate(move);
		}
	}
	*/

	cin.ignore(200, '\n');
	return 0;
}