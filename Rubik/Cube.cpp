//Alex Henry
//CS463 Assign 1
//Due 1/30/14

#include "Cube.h"
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

Cube::Cube() {
	char orig[24] = { 'y', 'y', 'y', 'y', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'o', 'o', 'b', 'b', 'r', 'r', 'g', 'g', 'w', 'w', 'w', 'w' };
	for (int i = 0; i < 24; i++) {
		cube[i] = orig[i];
	}

	history_size = 3;
	for (int i = 0; i < history_size; i++) {
		history[i] = -1;	//Initialize with a value that is not achievable under normal operation
	}
}

Cube::Cube(const Cube & inCube) {
	for (int i = 0; i < 24; i++) {
		cube[i] = inCube.get(i);
	}

	history_size = 3;
	for (int i = 0; i < history_size; i++) {
		history[i] = -1;	//Initialize with a value that is not achievable under normal operation
	}
}

void Cube::printCube() {
	cout << endl << "  " << cube[0] << cube[1] << endl;
	cout << "  " << cube[2] << cube[3] << endl;
	cout << "  " << "--" << endl;
	for (int i = 4; i < 12; i++) { cout << cube[i]; }
	cout << endl;
	for (int i = 12; i < 20; i++) { cout << cube[i]; }
	cout << endl;
	cout << "  " << "--" << endl;
	cout << "  " << cube[20] << cube[21] << endl;
	cout << "  " << cube[22] << cube[23];
}

void Cube::shuffleCube(int numMoves) {
	srand(time(NULL));

	int count = 0;
	bool execute = false;

	while (count < numMoves) {
		int move = rand() % 12;

		execute = testMove(move);

		//if execute is true then increment the count, make the move, and update the history array
		if (execute) {
			count++;

			switch (move) {
			case 0:
				frontClock();
				break;
			case 1:
				frontCounter();
				break;
			case 2:
				leftClock();
				break;
			case 3:
				leftCounter();
				break;
			case 4:
				topClock();
				break;
			case 5:
				topCounter();
				break;
			case 6:
				rightClock();
				break;
			case 7:
				rightCounter();
				break;
			case 8:
				bottomClock();
				break;
			case 9:
				bottomCounter();
				break;
			case 10:
				backClock();
				break;
			case 11:
				backCounter();
				break;
			}

			updateHistory(move);
		}
	}
}

char Cube::get(int index) const {
	return cube[index];
}

bool Cube::isSolved() {
	bool solved = true;
	//Yellow
	for (int i = 0; i < 4; i++) {
		if (cube[i] != 'y') { solved = false; }
	}

	//Orangle
	if (cube[4] != 'o') { solved = false; }
	if (cube[5] != 'o') { solved = false; }
	if (cube[12] != 'o') { solved = false; }
	if (cube[13] != 'o') { solved = false; }

	//Blue
	if (cube[6] != 'b') { solved = false; }
	if (cube[7] != 'b') { solved = false; }
	if (cube[14] != 'b') { solved = false; }
	if (cube[15] != 'b') { solved = false; }

	//Red
	if (cube[8] != 'r') { solved = false; }
	if (cube[9] != 'r') { solved = false; }
	if (cube[16] != 'r') { solved = false; }
	if (cube[17] != 'r') { solved = false; }

	//Green
	if (cube[10] != 'g') { solved = false; }
	if (cube[11] != 'g') { solved = false; }
	if (cube[18] != 'g') { solved = false; }
	if (cube[19] != 'g') { solved = false; }

	//White
	for (int i = 20; i < 24; i++)
	{
		if (cube[i] != 'w') { solved = false; }
	}

	return solved;
}

void Cube::userRotate(string move) {
	if (move.length() != 2) {
		cout << "Not a valid move!" << endl << endl;
	}
	else {
		bool valid = true;
		int intMove;
		if (move[0] == 'f' && move[1] == '*') {
			intMove = 0;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {		
				frontClock();
			}
		}
		else if (move[0] == 'f' && move[1] == ',') {
			intMove = 1;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				frontCounter();
			}
		}
		else if (move[0] == 'l' && move[1] == '*') {
			intMove = 2;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				leftClock();
			}
		}
		else if (move[0] == 'l' && move[1] == ',') {
			intMove = 3;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				leftCounter();
			}
		}
		else if (move[0] == 'r' && move[1] == '*') {
			intMove = 6;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				rightClock();
			}
		}
		else if (move[0] == 'r' && move[1] == ',') {
			intMove = 7;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				rightCounter();
			}
		}
		else if (move[0] == 't' && move[1] == '*') {
			intMove = 4;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				topClock();
			}
		}
		else if (move[0] == 't' && move[1] == ',') {
			intMove = 5;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				topCounter();
			}
		}
		else if (move[0] == 'b' && move[1] == '*') {
			intMove = 8;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				bottomClock();
			}
		}
		else if (move[0] == 'b' && move[1] == ',') {
			intMove = 9;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				bottomCounter();
			}
		}
		else if (move[0] == 'a' && move[1] == '*') {
			intMove = 10;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				backClock();
			}
		}
		else if (move[0] == 'a' && move[1] == ',') {
			intMove = 11;
			valid = testMove(intMove);	//Use the integer representation of the move (show in the testMove code)
			if (valid) {
				backCounter();
			}
		} else {
			valid = false;
		}

		cout << endl;
		if (valid) { 
			printCube();
			cout << endl << endl;
			updateHistory(intMove);
		}
		else {
			cout << "Invalid move!" << endl << endl;
		}
	}
}

bool Cube::testMove(int move) {
	bool execute = false;
	/*
	Assign each move a number. I have arbitrarily done
	frontClock = 0, frontCounter = 1, leftClock = 2, leftCounter = 3, topClock = 4, topCounter = 5
	rightClock = 6, rightCounter = 7, bottomClock = 8, bottomCounter = 9, backClock = 10, backCounter = 11
	*/

	//Defend against cases in which the movement would be pointless
	//Defend against the same move four times in a row. Use the history array
	//Check if the proposed move is the same as the previous 3
	bool same = false;
	if (history[0] == move && history[1] == move && history[2] == move) {
		same = true;
	}

	//Defend against opposing moves are made back to back (frontClock then frontCounter)
	//Most recent move in the history array is 0.
	bool cancel = false;
	switch (move) {
	case 0:
		if (history[0] == 1) {
			cancel = true;
		}
		break;
	case 1:
		if (history[0] == 0) {
			cancel = true;
		}
		break;
	case 2:
		if (history[0] == 3) {
			cancel = true;
		}
		break;
	case 3:
		if (history[0] == 2) {
			cancel = true;
		}
		break;
	case 4:
		if (history[0] == 5) {
			cancel = true;
		}
		break;
	case 5:
		if (history[0] == 4) {
			cancel = true;
		}
		break;
	case 6:
		if (history[0] == 7) {
			cancel = true;
		}
		break;
	case 7:
		if (history[0] == 6) {
			cancel = true;
		}
		break;
	case 8:
		if (history[0] == 9) {
			cancel = true;
		}
		break;
	case 9:
		if (history[0] == 8) {
			cancel = true;
		}
		break;
	case 10:
		if (history[0] == 11) {
			cancel = true;
		}
		break;
	case 11:
		if (history[0] == 10) {
			cancel = true;
		}
		break;
	default:
		//not reachable
		cancel = true;
		break;
	}

	//Check if the move is valid
	if (!cancel && !same) {
		execute = true;
	}

	return execute;
}

void Cube::updateHistory(int move) {
	//Update the history array
	for (int i = history_size - 1; i > 0; i--) {
		history[i] = history[i - 1];	//Move values back to make room for the new move
	}

	history[0] = move;	//Set the most recent move
}

float Cube::heuristicGuess() {
	int numMisplaced = 0;
	float guess = 0;

	//Yellow
	for (int i = 0; i < 4; i++) {
		if (cube[i] != 'y') { numMisplaced++; }
	}

	//Orangle
	if (cube[4] != 'o') { numMisplaced++; }
	if (cube[5] != 'o') { numMisplaced++; }
	if (cube[12] != 'o') { numMisplaced++; }
	if (cube[13] != 'o') { numMisplaced++; }

	//Blue
	if (cube[6] != 'b') { numMisplaced++; }
	if (cube[7] != 'b') { numMisplaced++; }
	if (cube[14] != 'b') { numMisplaced++; }
	if (cube[15] != 'b') { numMisplaced++; }

	//Red
	if (cube[8] != 'r') { numMisplaced++; }
	if (cube[9] != 'r') { numMisplaced++; }
	if (cube[16] != 'r') { numMisplaced++; }
	if (cube[17] != 'r') { numMisplaced++; }

	//Green
	if (cube[10] != 'g') { numMisplaced++; }
	if (cube[11] != 'g') { numMisplaced++; }
	if (cube[18] != 'g') { numMisplaced++; }
	if (cube[19] != 'g') { numMisplaced++; }

	//White
	for (int i = 20; i < 24; i++)
	{
		if (cube[i] != 'w') { numMisplaced++; }
	}

	//Calculate guess
	float eight = 8.0;
	guess = numMisplaced / eight;
	return guess;
}

void Cube::frontClock() {
	char temp2 = cube[2];
	char temp3 = cube[3];
	char temp20 = cube[20];
	char temp21 = cube[21];

	cube[2] = cube[13];
	cube[3] = cube[5];
	cube[20] = cube[16];
	cube[21] = cube[8];
	cube[8] = temp2;
	cube[16] = temp3;
	cube[5] = temp20;
	cube[13] = temp21;

	//Changes the front
	char temp6 = cube[6];
	char temp15 = cube[15];

	cube[6] = cube[14];
	cube[15] = cube[7];
	cube[14] = temp15;
	cube[7] = temp6;
}

void Cube::frontCounter() {
	char temp2 = cube[2];
	char temp3 = cube[3];
	char temp20 = cube[20];
	char temp21 = cube[21];

	cube[2] = cube[8];
	cube[3] = cube[16];
	cube[20] = cube[5];
	cube[21] = cube[13];
	cube[8] = temp21;
	cube[16] = temp20;
	cube[5] = temp3;
	cube[13] = temp2;

	//Changes the front
	char temp6 = cube[6];
	char temp15 = cube[15];

	cube[6] = cube[7];
	cube[15] = cube[14];
	cube[14] = temp6;
	cube[7] = temp15;
}

void Cube::leftClock() {
	char temp0 = cube[0];
	char temp2 = cube[2];
	char temp20 = cube[20];
	char temp22 = cube[22];

	cube[0] = cube[19];
	cube[2] = cube[11];
	cube[20] = cube[6];
	cube[22] = cube[14];
	cube[6] = temp0;
	cube[14] = temp2;
	cube[11] = temp22;
	cube[19] = temp20;

	//Will also alter the side
	char temp5 = cube[5];
	char temp12 = cube[12];

	cube[5] = cube[4];
	cube[12] = cube[13];
	cube[13] = temp5;
	cube[4] = temp12;
}

void Cube::leftCounter() {
	char temp0 = cube[0];
	char temp2 = cube[2];
	char temp20 = cube[20];
	char temp22 = cube[22];

	cube[0] = cube[6];
	cube[2] = cube[14];
	cube[20] = cube[19];
	cube[22] = cube[11];
	cube[6] = temp20;
	cube[14] = temp22;
	cube[19] = temp0;
	cube[11] = temp2;

	//Will also alter the side
	char temp4 = cube[4];
	char temp13 = cube[13];

	cube[4] = cube[5];
	cube[13] = cube[12];
	cube[12] = temp4;
	cube[5] = temp13;
}

void Cube::topClock() {
	char temp6 = cube[6];
	char temp7 = cube[7];
	char temp10 = cube[10];
	char temp11 = cube[11];

	cube[6] = cube[8];
	cube[7] = cube[9];
	cube[10] = cube[4];
	cube[11] = cube[5];
	cube[8] = temp10;
	cube[9] = temp11;
	cube[4] = temp6;
	cube[5] = temp7;

	//Will also alter the top
	char temp0 = cube[0];
	char temp3 = cube[3];

	cube[0] = cube[2];
	cube[3] = cube[1];
	cube[1] = temp0;
	cube[2] = temp3;
}

void Cube::topCounter() {
	char temp6 = cube[6];
	char temp7 = cube[7];
	char temp10 = cube[10];
	char temp11 = cube[11];

	cube[6] = cube[8];
	cube[7] = cube[9];
	cube[10] = cube[4];
	cube[11] = cube[5];
	cube[8] = temp10;
	cube[9] = temp11;
	cube[4] = temp6;
	cube[5] = temp7;

	//Will also alter the top
	char temp0 = cube[0];
	char temp3 = cube[3];

	cube[0] = cube[2];
	cube[3] = cube[1];
	cube[1] = temp0;
	cube[2] = temp3;
}

void Cube::rightClock() {
	char temp1 = cube[1];
	char temp3 = cube[3];
	char temp21 = cube[21];
	char temp23 = cube[23];

	cube[1] = cube[7];
	cube[3] = cube[15];
	cube[21] = cube[18];
	cube[23] = cube[10];
	cube[7] = temp21;
	cube[15] = temp23;
	cube[10] = temp3;
	cube[18] = temp1;

	//Will also alter the side
	char temp8 = cube[8];
	char temp17 = cube[17];

	cube[8] = cube[16];
	cube[17] = cube[9];
	cube[16] = temp17;
	cube[9] = temp8;
}

void Cube::rightCounter() {
	char temp1 = cube[1];
	char temp3 = cube[3];
	char temp21 = cube[21];
	char temp23 = cube[23];

	cube[1] = cube[18];
	cube[3] = cube[10];
	cube[21] = cube[7];
	cube[23] = cube[15];
	cube[7] = temp1;
	cube[15] = temp3;
	cube[10] = temp23;
	cube[18] = temp21;

	//Will also alter the side
	char temp8 = cube[8];
	char temp17 = cube[17];

	cube[8] = cube[9];
	cube[17] = cube[16];
	cube[16] = temp8;
	cube[9] = temp17;
}

void Cube::bottomClock() {
	char temp14 = cube[14];
	char temp15 = cube[15];
	char temp18 = cube[18];
	char temp19 = cube[19];

	cube[14] = cube[12];
	cube[15] = cube[13];
	cube[18] = cube[16];
	cube[19] = cube[17];
	cube[16] = temp14;
	cube[17] = temp15;
	cube[12] = temp18;
	cube[13] = temp19;

	//Will alter the bottom
	char temp21 = cube[21];
	char temp22 = cube[22];

	cube[21] = cube[20];
	cube[22] = cube[23];
	cube[20] = temp22;
	cube[23] = temp21;
}

void Cube::bottomCounter() {
	char temp14 = cube[14];
	char temp15 = cube[15];
	char temp18 = cube[18];
	char temp19 = cube[19];

	cube[14] = cube[16];
	cube[15] = cube[17];
	cube[18] = cube[12];
	cube[19] = cube[13];
	cube[16] = temp18;
	cube[17] = temp19;
	cube[12] = temp14;
	cube[13] = temp15;

	//Will alter the bottom
	char temp21 = cube[21];
	char temp22 = cube[22];

	cube[21] = cube[23];
	cube[22] = cube[20];
	cube[20] = temp21;
	cube[23] = temp22;
}

void Cube::backClock() {
	char temp0 = cube[0];
	char temp1 = cube[1];
	char temp22 = cube[22];
	char temp23 = cube[23];

	cube[0] = cube[9];
	cube[1] = cube[17];
	cube[22] = cube[4];
	cube[23] = cube[12];
	cube[9] = temp23;
	cube[17] = temp22;
	cube[4] = temp1;
	cube[12] = temp0;

	//Changes the back
	char temp10 = cube[10];
	char temp19 = cube[19];

	cube[10] = cube[18];
	cube[19] = cube[11];
	cube[11] = temp10;
	cube[18] = temp19;
}

void Cube::backCounter() {
	char temp0 = cube[0];
	char temp1 = cube[1];
	char temp22 = cube[22];
	char temp23 = cube[23];

	cube[0] = cube[12];
	cube[1] = cube[4];
	cube[22] = cube[17];
	cube[23] = cube[9];
	cube[9] = temp0;
	cube[17] = temp1;
	cube[4] = temp22;
	cube[12] = temp23;

	//Changes the back
	char temp10 = cube[10];
	char temp19 = cube[19];

	cube[10] = cube[11];
	cube[19] = cube[18];
	cube[11] = temp19;
	cube[18] = temp10;
}
