//Alex Henry
//CS463 Assign 1
//Due 1/30/14
#ifndef CUBE_H
#define CUBE_H
#include <string>

class Cube {
public:
	Cube();
	Cube(const Cube & inCube);

	void printCube();
	void shuffleCube(int numMoves);
	char get(int index) const;
	bool isSolved();

	//Get guess of the heuristic
	float heuristicGuess();

	/*
	Function that allows for the user to input moves manually. Takes in a string
	of length two. The command is in the form of string[0] = face and string[1] = direction.
	For the face:
	f = front
	l = left
	r = right
	t = top
	b = bottom
	a = back

	For the direction (direction is specified as if you were looking at the face you are going
	to manipulate). So if you are looking from the front, a back clockwise move looks counterclockwise.
	* = clockwise
	, = counterclockwise
	*/
	void userRotate(std::string move);


	/*Turns the specified side. We specify the front as the
	solved blue side. Direction is based on if you are looking at the face.
	Front = Blue
	Left = Orange
	Top = Yellow
	Bottom = White
	Right = Red
	Back = Green
	*/
	void frontClock();
	void frontCounter();
	void leftClock();
	void leftCounter();
	void topClock();
	void topCounter();
	void rightClock();
	void rightCounter();
	void bottomClock();
	void bottomCounter();
	void backClock();
	void backCounter();

private:
	char cube[24];
	int history_size;
	int history[3];

	//Looks at history and determins if the move is valid
	bool testMove(int move);

	//Method to update the move history
	void updateHistory(int move);
};

#endif