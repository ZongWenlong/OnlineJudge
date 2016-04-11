#include <iostream>
#include <string>
#include <list>

#define	BOARD_SIZE 4
using namespace std;


int main()
{
	bool mask[BOARD_SIZE][BOARD_SIZE];
	list<int> row;
	list<int> column;

	int board = 0;
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			mask[i][j] = false;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		string row;
		getline(cin, row);
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (row[j] == '+') {
				mask[i][j] = !mask[i][j];
				for (int k = 0; k < BOARD_SIZE; k++) {
					mask[i][k] = !mask[i][k];
					mask[k][j] = !mask[k][j];
				}
			}
				
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (mask[i][j] == true) {
				row.push_back(i + 1);
				column.push_back(j + 1);
			}
		}
	}
	cout << row.size() << endl;

	for (list<int>::iterator it = row.begin(),it2 = column.begin(); it != row.end() && it2 != column.end(); it++,it2++) {
		cout << (*it) << " " << (*it2) << endl;
	}

	getchar();
	return 0;
}

