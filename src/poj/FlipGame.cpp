#include <iostream>
#include <string>
#include <list>

#define	BOARD_SIZE 4
using namespace std;

void recursion(bool chessboard[BOARD_SIZE][BOARD_SIZE], int index);
void changeBoard(bool chessboard[BOARD_SIZE][BOARD_SIZE], int row, int column);
bool checkWin(bool chessboard[BOARD_SIZE][BOARD_SIZE]);
void print(bool chessboard[BOARD_SIZE][BOARD_SIZE]);

int minVaule = BOARD_SIZE * BOARD_SIZE + 1;
int cur = 0;
int main()
{
	bool chessboard[BOARD_SIZE][BOARD_SIZE];

	for (int i = 0; i < BOARD_SIZE; i++) {
		string row;
		getline(cin, row);
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (row[j] == 'b')
				chessboard[i][j] = true;
			else
				chessboard[i][j] = false;
		}
	}

	recursion(chessboard,0);
	if (minVaule == BOARD_SIZE * BOARD_SIZE + 1) {
		cout << "Impossible" << endl;
	}
	else {
		cout << minVaule << endl;
	}
	

	return 0;
}

void recursion(bool chessboard[BOARD_SIZE][BOARD_SIZE], int index) {
	if (index < BOARD_SIZE * BOARD_SIZE) {

		//current not change
		int row = index / BOARD_SIZE;
		int column = index % BOARD_SIZE;

		if (checkWin(chessboard) == true) {
			if (cur < minVaule) {
				minVaule = cur;
			}
		}
		else {
			recursion(chessboard, index + 1);
		}

		//current change
		cur++;
		changeBoard(chessboard, row, column);
		if (checkWin(chessboard) == true) {
			if (cur < minVaule) {
				minVaule = cur;
			}
		}
		else {
			recursion(chessboard, index + 1);
		}
		cur--;
		changeBoard(chessboard, row, column);
	}
	
}

void changeBoard(bool chessboard[BOARD_SIZE][BOARD_SIZE], int row, int column) {
	chessboard[row][column] = !chessboard[row][column];
	if (row + 1 < BOARD_SIZE ) {
		chessboard[row + 1][column] = !chessboard[row + 1][column];
	}
	if (row - 1 >= 0) {
		chessboard[row - 1][column] = !chessboard[row - 1][column];
	}
	if (column + 1 < BOARD_SIZE) {
		chessboard[row][column + 1] = !chessboard[row][column + 1];
	}
	if (column - 1 >= 0) {
		chessboard[row][column - 1] = !chessboard[row][column - 1];
	}
	
}

bool checkWin(bool chessboard[BOARD_SIZE][BOARD_SIZE])
{
	bool flag = chessboard[0][0];
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (chessboard[i][j] != flag) {
				return false;
			}
		}
	}
	return true;
}


void print(bool chessboard[BOARD_SIZE][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (chessboard[i][j] == true) {
				cout << "b";
			}
			else {
				cout << "w";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}