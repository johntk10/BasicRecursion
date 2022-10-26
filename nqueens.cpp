// CS202
// Lab 7:  N-queens using backtracking 

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

void nqueens(int Board[], int col, int size) {
	// This was given in the writeup, but it basically
	// continues to add queens until every column has one.
	if (col < size) {
		for (int i = 0;i < size;i++) {
			Board[col] = i;
			nqueens(Board, col+1, size);
		}
	} else {
		// Once all the queens are placed, it runs error checks.
		int fail = 0;
		for (int t = 0;t < size;t++) {
			for (int j = 0;j < size;j++) {
				if (Board[t] == Board[j] && t != j) {
					fail = 1;
				} else if (abs(Board[t] - Board[j]) == abs(t - j) && t != j) {
					fail = 1;
				}
			}
		}
		if (fail == 0) {
			for (int f = 0;f < size-1;f++) {
				cout << Board[f] << ", ";
			}
			cout << Board[size-1] << endl;
		}
	}
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
		cout << "Usage Error <./nqueens> <size>" << endl;
		return -1;
	}
	istringstream ss(argv[1]);
	int size;
	if (!(ss >> size)) {
		cout << "Not valid input" << endl;
	}
	int Board[size];
	nqueens(Board, 0, size);
}

                                                                                                                                                                                                                                                                                                                                                                                                                                   nqueens2.cpp                                                                                        0000600 0065671 0017021 00000002542 14325065307 013240  0                                                                                                    ustar   jkutbay                         jkutbay                                                                                                                                                                                                                // John Kutbay
// CS202
// 10/20/2022
// Lab 7: nqueens2

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

// This checks first to see if the same row queen has been placed,
// then if the diagonal queen has been placed.
bool isValid(int Board[], int size) {
	for (int t = 0;t < size;t++) {
		for (int f = 0;f < size;f++) {
			if (Board[t] == Board[f] && t != f) {
				return false;
			} else if (abs(Board[t] - Board[f]) == abs(t - f) && t != f) {
				return false;
			}
		}
	}
	return true;
}
// This is my helper function for printing my board.
void printBoard(int Board[], int size) {
	for (int c = 0;c < size-1;c++) {
		cout << Board[c] << ", ";
	}
	cout << Board[size-1] << endl;
}

// This runs the same as nqueens.cpp with the isValid function check
// added in.
void nqueens(int Board[], int col, int size) {
	if (col < size) {
		for (int i = 0;i < size;i++) {
			Board[col] = i;
			if (isValid(Board, col) == true) {
				nqueens(Board, col+1, size);
			} else {
				break;
			}
		}
	} else {
		if (isValid(Board, size) == true) {
			printBoard(Board, size);
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage Error <./nqueens2> <size>" << endl;
		return -1;
	}
	istringstream ss(argv[1]);
	int size;
	if (!(ss >> size)) {
		cout << "Not valid input" << endl;
	}
	int Board[size];
	nqueens(Board, 0, size);
}
