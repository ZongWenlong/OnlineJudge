#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
* 求最大字段和
*/
int maxSubSequence(vector<int>& arr) {
	if (arr.size() > 0) {
		int maxSub = arr[0];
		int temp = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			if (temp > 0) {
				temp = temp + arr[i];
			}
			else {
				temp = arr[i];
			}
			maxSub = max(maxSub, temp);
		}
		return maxSub;
	}
	else {
		return 0;
	}
}



int main()
{
	int m, n;
	cin >> m >> n;

	//初始化
	vector<vector<int> > nums(n);
	vector<vector<int> > total(n);
	for (int i = 0; i < n; i++) {
		vector<int> row(m);
		vector<int> totalRow(m);
		if (i == 0) {
			for (int j = 0; j < m; j++) {
				cin >> row[j];
				totalRow[j] = row[j];
			}
		}
		else {
			for (int j = 0; j < m; j++) {
				cin >> row[j];
				totalRow[j] = total[i - 1][j] + row[j];
			}
		}

		nums[i] = row;
		total[i] = totalRow;
	}

	int maxSub = INT_MIN;
	// 最大子矩阵行数为 i
	vector<int> result(n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (i == j || i == 0) {
					result[k] = total[j][k];
				}
				else {
					result[k] = total[j][k] - total[j - i][k];
				}
			}
			int maxTemp = maxSubSequence(result);
			if (maxTemp > maxSub) {
				maxSub = maxTemp;
			}
		}
	}
	cout << maxSub << endl;
	return 0;
}
