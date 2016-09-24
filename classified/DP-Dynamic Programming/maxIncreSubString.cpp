#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		total = total+ nums[i];
	}

	int half = total / 2;
	vector<vector<int> > f(n + 1);
	for (int i = 0; i <= n; i++) {
		vector<int> temp(half + 1);
		f[i] = temp;
	}

	vector<vector<int> >::iterator fIter = f.begin();
    fill((*fIter).begin(),(*fIter).end(),0);

	for(int i = 1; i <= n;i++){
        for(int j = 1; j <= half;j++){
            if(nums[i - 1] > j){
                f[i][j] = f[i - 1][j];
            }
            else{
                f[i][j] = max(f[i - 1][j],f[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
        }
	}

	cout << (total - 2*f[n][half])  << endl;
}
