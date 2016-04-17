#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

typedef struct {
    int x;
    int y;
} Pointer;

int bsf( vector<vector<char> > &board,vector<vector<int> > &distance){
    list<Pointer> pointerList;
    int directionX[4] = {0,0,-1,1};
    int directionY[4] = {-1,1,0,0};

    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[i].size() ;j++){
            if(board[i][j] == 'S'){
                Pointer p;
                p.x = i;
                p.y = j;
                distance[i][j] = 0;
                pointerList.push_back(p);
                while(pointerList.size() > 0){
                    Pointer cur =  pointerList.front();
                    pointerList.pop_front();

                    for(int k = 0; k < 4;k++){
                        Pointer newP;
                        newP.x = cur.x + directionX[k];
                        newP.y = cur.y + directionY[k];

                        if(newP.x >= 0 && newP.x < board[i].size() &&
                           newP.y >= 0 && newP.y < board[i].size() &&
                           distance[newP.x][newP.y] == -1 && board[newP.x][newP.y] != '#')
                        {
                            if(board[newP.x][newP.y] == '.'){
                                distance[newP.x][newP.y] = distance[cur.x][cur.y] + 1;
                                pointerList.push_back(newP);
                            }
                            else if(board[newP.x][newP.y] == 'G'){
                                return distance[cur.x][cur.y] + 1;
                            }

                        }
                    }
                }
            }
        }
    }

    return -1;

}


int main()
{
    int row,column;
    cin >> row >> column;

    vector<vector<char> > board(row);
    vector<vector<int> > distance(row);
    for(int i = 0; i < row;i++ ){
        vector<char> rowBoard(column);
        vector<int> rowDistance(column);
        board[i] = rowBoard;
        distance[i] = rowDistance;
    }

    for(int i = 0; i < row;i++){
        string line;
        cin>>line;
        for(int j = 0; j < column ;j++){
            board[i][j] = line[j];
            distance[i][j] = -1;
        }
    }

    cout<<bsf(board,distance);

    return 0;
}
