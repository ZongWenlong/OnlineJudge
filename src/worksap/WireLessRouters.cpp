#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * This solution has some problems.
 * Greedy algorithm can't find the optimal solution.
 * I know tree dynamic programming may solve this proble, 
 * but I can't make it even after a long time trying.
 */


typedef struct Room {
	int point;
	unordered_set<int> neighbors;
}Room;

int main()
{
	int n, m;
	vector<Room> rooms;
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		Room room;
		cin >> room.point;
		rooms.push_back(room);
	}

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		rooms[x].neighbors.insert(y);
		rooms[y].neighbors.insert(x);
	}

	int total = 0;
	int maxPoint = 0;
	int maxPointIndex = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int curPoint = rooms[j].point;
			for (int indexTemp : rooms[j].neighbors) {
				curPoint += rooms[indexTemp].point;
			}
			if (curPoint > maxPoint) {
				maxPoint = curPoint;
				maxPointIndex = j;
			}
		}
		total += maxPoint;
		rooms[maxPointIndex].point = 0;
		for (int indexTemp : rooms[maxPointIndex].neighbors) {
			rooms[indexTemp].point = 0;
		}
		maxPoint = 0;
	}
	cout << total << endl;

	system("pause");
	return 0;
}