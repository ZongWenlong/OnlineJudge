#include <iostream>
#include <string>
#include <vector>
using namespace std;


void dfs(int row,int column,vector<vector<bool> > &board){
    board[row][column] = false;
    for(int i = row > 0 ? row - 1: row; i <= row + 1 && i < board.size();i ++ ){
        for(int j = column > 0 ? column - 1 : column; j <= column + 1 && j < board[0].size();j++){
            if(board[i][j] == true){
                dfs(i,j,board);
            }
        }
    }


}

int main()
{
    int row,column;
    cin >> row >> column;

    vector<vector<bool> > board(row);
    for(int i = 0; i < row;i++ ){
        vector<bool> rowBoard(column);
        board[i] = rowBoard;
    }
    for(int i = 0; i < row;i++){
        string line;
        cin>>line;
        for(int j = 0; j < column ;j++){
            if(line[j] == 'W')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }

    int pondNum = 0;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < column ;j++){
                if(board[i][j] == true){
                    pondNum ++;
                    dfs(i,j,board);
                }
        }
    }
    cout<<pondNum;

    return 0;
}
