#include <iostream>
#include <vector>
#include <cstdio>

#define W 0
#define N 1
#define E 2
#define S 3

using namespace std;

typedef struct {
	int x;
	int y;
	int d;
}RobotStaus;

int main()
{
	int xMove[4] = { 0,1,0,-1 };
	int yMove[4] = { -1,0,1,0 };
	int caseNum;
	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {
		int width, height;
		cin >> width >> height;

		vector<vector<int> >board(height);
		for (int j = 0; j < height; j++) {
			vector<int> row(width, -1);
			board[j] = row;
		}

		int robotNum, instrNum;
		cin >> robotNum >> instrNum;

		vector<RobotStaus> robots(robotNum);
		for (int j = 0; j < robotNum; j++) {
			RobotStaus r;
			cin >> r.y >> r.x;
			r.x--;
			r.y--;
			getchar();
			switch (getchar()) {
			case 'W':
				r.d = W;
				break;
			case 'N':
				r.d = N;
				break;
			case 'E':
				r.d = E;
				break;
			case 'S':
				r.d = S;
				break;
			default:
				break;
			}

			robots[j] = r;
			if (board[r.x][r.y] != -1) {
				cout << "Robot " << j + 1 << " crashes into robot " << board[r.x][r.y] + 1;
				break;
			}
			else {
				board[r.x][r.y] = j;
			}
		}

		bool endFlag = false;
		for (int j = 0; j < instrNum; j++) {
			int robotId;
			char instr;
			int repeatNum;
			cin >> robotId;
			robotId--;
			getchar();
			instr = getchar();
			cin >> repeatNum;

			for (int k = 0; k < repeatNum && endFlag == false; k++) {
				switch (instr) {
				case 'L':
					robots[robotId].d = (robots[robotId].d + 4 - 1) % 4;
					break;
				case 'R':
					robots[robotId].d = (robots[robotId].d + 1) % 4;
					break;
				case 'F':
				{
					RobotStaus r = robots[robotId];
					r.x = r.x + xMove[r.d];
					r.y = r.y + yMove[r.d];
					if (r.x < 0 || r.x >= height || r.y < 0 || r.y >= width) {
						printf("Robot %d crashes into the wall\n", robotId + 1);
						endFlag = true;
					}
					else if (board[r.x][r.y] != -1) {
						printf("Robot %d crashes into robot %d\n", robotId + 1, board[r.x][r.y] + 1);
						endFlag = true;
					}
					else {
						board[robots[robotId].x][robots[robotId].y] = -1;
						board[r.x][r.y] = robotId;
						robots[robotId] = r;
					}

					break;
				}
				default:
					break;
				}
			}

		}

		if (endFlag == false) {
			cout << "OK" << endl;
		}
	}



	return 0;
}
