#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int endFlag;


bool lineSort (vector<int> a,vector<int> b) { return (a[0] < b[0]); }

bool check(int num,int rowIndex,int colIndex, vector<bool> flag,vector<vector<int> > &board){
    if(flag[rowIndex] == false){
        return true;
    }
    return num == board[rowIndex][colIndex];
}


void dfs(vector<vector<int> > &lineList,int index, vector<vector<int> > rowBoard,vector<vector<int> > colBoard, vector<bool> rowFlag, vector<bool> colFlag,int rowIndex,int colIndex){
    if(index == endFlag){

    }
    else{
        if(check(lineList[index][0],0,))
    }



    if(rowFlag[0] == true){

    }
    if(colFlag[0] == true){

    }
    if(rowIndex <= 1 && colIndex <= 1){
        if(n >= 3){
            if(lineList[n - 1][n - 1] == lineList[n - 1][n - 1]){
                if(check(lineList[lineList.size() - 1][0],0,) )
                rowBoard[n - 1] = lineList[lineList.size() - 1];
                colBoard[n - 1] = lineList[lineList.size() - 2];
                rowFlag[0] = true;
                colFlag[0] = true;
            }


            rowFlag[0] = true;
            colFlag[0] = true;
        }
    }
}


int main()
{
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum; ){
        cin >> n;
        endFlag = n * n - 1;
        vector<vector<int> > lineList(endFlag);
        vector<vector<int> > rowBoard(n);
        vector<vector<int> > colBoard(n);
        vector<bool> rowFlag(n,false);
        vector<bool> colFlag(n,false);

        for(int j = 0; j < endFlag;j++ ){
            vector<int> lineRow(n);
            vector<int> boardRow(n,-1);
            for(int k = 0; k < n;k++){
                cin >> lineRow[k];
            }
            lineList[j] = lineRow;
            board[j] = boardRow;
        }
        sort(lineList.begin(),lineList.end(),lineSort());

        int rowIndex = 0;
        int colIndex = 0;
        if(lineList[0][0] == lineList[1][1]){
            rowBoard[0] = lineList[0];
            colBoard[0] = lineList[1];
            rowFlag[0] = true;
            colFlag[0] = true;
            rowIndex++;
            colIndex++;
        }
        else{
            rowBoard[0] = lineList[0];
            rowFlag[0] = true;
            rowIndex++;
        }
        dfs(lineList,rowBoard,colBoard,rowFlag,colFlag,rowInde,colIndex);
    }
    return 0;
}
