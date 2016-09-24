#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
int main()
{
	int num;
	cin >> num;
	priority_queue<int,vector<int>, greater<int> > lens;
	for(int i = 0,temp = 0;i < num;i++){
		cin >> temp;
		lens.push(temp);
	}

	long long result = 0;

	while(lens.size() > 1){
		int l1,l2;
		l1 = lens.top();
		lens.pop();
		l2 = lens.top();
		lens.pop();

		result += l1+l2;
		lens.push(l1 + l2);
	}
	cout<<result;
	return 0;

}