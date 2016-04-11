#include <iostream>
#include <cmath>

using namespace std;

#define TOTAL_SIZE 12
#define GROUP_SIZE 5

int getMaxSurplus(int s, int d) {
	int postsNum = TOTAL_SIZE - GROUP_SIZE + 1;
	int sNum = GROUP_SIZE * d / (d + s);
	if ((GROUP_SIZE * s) % (d + s) == 0) {
		sNum--;
	}
	if (sNum == 0) {
		return -1;
	}

	int groupRowNum = sNum + 1;
	int inGroupLine = groupRowNum > postsNum % GROUP_SIZE ? postsNum % GROUP_SIZE : groupRowNum;
	int sTotalNum = (postsNum / GROUP_SIZE + 1) * (sNum)+inGroupLine - 1;
	int surplus = s * (sTotalNum) - (12 - sTotalNum) * d;
	return surplus;
}

int main()
{
	int s, d;
	while (cin >> s >> d) {
		int surplus = getMaxSurplus(s, d);
		if (surplus >= 0) {
			cout << surplus << "\n";
		}
		else {
			cout << "Deficit" << "\n";
		}
	}
	return 0;
}




