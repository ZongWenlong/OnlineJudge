#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
int main()
{
	int n;
    cin >>n;

    ll cur,preMax,preMin;
    cin >> preMax;
    ll total = preMax;
    ll maxSub = preMax;
    ll minSub = preMax;
    preMin = preMax;
    for(int i = 1;i < n;i++){
        cin >> cur;
        total = total + cur;
        if(preMax > 0){
            preMax = preMax + cur;
        }
        else{
            preMax = cur;
        }
        if(preMin < 0){
            preMin = preMin + cur;
        }
        else{
            preMin = cur;
        }
        maxSub = max(maxSub,preMax);
        minSub = min(minSub,preMin);
    }

	cout << max(maxSub,total - minSub) << endl;
	return 0;
}
