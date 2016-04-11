#include <iostream>
#include <string>
#include <list>

#define	BOARD_SIZE 4
using namespace std;

int minVaule = BOARD_SIZE * BOARD_SIZE + 1;
int cur = 0;
list<int> sequence;
list<int>  sequenceTemp;

int mask[BOARD_SIZE * BOARD_SIZE];
void initMask() 
{	
	int rowMask[BOARD_SIZE];
	int columnMask[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) {
		rowMask[i] = (0x0F << (i*BOARD_SIZE));
		columnMask[i] = 0;
		for (int j = 0; j < BOARD_SIZE; j++) {
			columnMask[i] = columnMask[i] | (1 << (BOARD_SIZE*j + i));
		}
		
	}
	
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
		mask[i] = (1 << i) ^ rowMask[i / BOARD_SIZE] ^ columnMask[i%BOARD_SIZE];
	}

}


void recursion(int board, int index) {
	if (board == 0) {
		if (cur < minVaule) {
			minVaule = cur;
			sequence = sequenceTemp;
		}
		return;
	}

	if (index < BOARD_SIZE * BOARD_SIZE) {

		//current not change
		int row = index / BOARD_SIZE;
		int column = index % BOARD_SIZE;

		recursion(board, index + 1);

		int temp = board;
		//current change
		cur++;
		board = board ^ mask[index];
		sequenceTemp.push_back(index);
		recursion(board, index + 1);

		cur--;
		board =  temp;
		sequenceTemp.pop_back();
	}

}


int main()
{
	initMask();

	int board = 0;
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		string row;
		getline(cin, row);
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (row[j] == '+')
				board |= (1 << index);
			index++;
				
		}
	}

	recursion(board, 0);

	cout << minVaule << endl;

	for (list<int>::iterator it = sequence.begin(); it != sequence.end(); it++) {
		cout << (*it / BOARD_SIZE + 1) << " " << (*it % BOARD_SIZE + 1) << endl;
	}

	return 0;
}

