#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

#define W 0
#define N 1
#define E 2
#define S 3

using namespace std;

int main()
{
	int rowMove[4] = { 0,-1,0,1 };
	int colMove[4] = { -1,0,1,0 };

    int rowNum,colNum,initCol;
    cin >> rowNum >> colNum >> initCol;
    while(rowNum != 0){
        vector<vector<int> > board(rowNum);
        vector<vector<int> > flag(rowNum);
        for(int i = 0; i < rowNum; i++){
            string line;
            cin >> line;
            vector<int> row(colNum);
            vector<int> flagRow(colNum);
            for(int j = 0; j < colNum;j++){
                switch(line[j]){
                case 'W':
                    row[j] = W;
                    break;
                case 'N':
                    row[j] = N;
                    break;
                case 'E':
                    row[j] = E;
                    break;
                case 'S':
                    row[j] = S;
                    break;
                }
                flagRow[j] = -1;
            }
            board[i] = row;
            flag[i] = flagRow;
        }

        bool endFlag = false;
        int curRow = 0,curCol = initCol - 1;
        int totalStepNum = 0;
        flag[curRow][curCol] = 0;
        while(true){
            totalStepNum++;
            int nextRow = curRow + rowMove[board[curRow][curCol]];
            int nextCol = curCol + colMove[board[curRow][curCol]];
            if(nextRow < 0 || nextRow >= rowNum || nextCol < 0 || nextCol >= colNum){
                printf("%d step(s) to exit\n",totalStepNum);
                break;
            }
            else if(flag[nextRow][nextCol] != -1){
                printf("%d step(s) before a loop of %d step(s)\n",flag[nextRow][nextCol],totalStepNum - flag[nextRow][nextCol]);
                break;
            }
            else{
                flag[nextRow][nextCol] = totalStepNum;
                curRow = nextRow;
                curCol = nextCol;

            }
        }
        cin >> rowNum >> colNum >> initCol;


    }

	return 0;
}
