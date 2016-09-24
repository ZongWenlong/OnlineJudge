#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef struct {
	int d;
	int f;
} Stop;
bool compare(Stop a, Stop b){
	return a.d < b.d;
}

int solve(){
	// handle input
	int stopNum;
	cin >> stopNum;
	vector<Stop>  stops(stopNum + 1);
	for(int i = 0; i < stopNum;i++){
		Stop stop;
		cin >> stop.d >> stop.f;
		stops[i] = stop;
	}
	int totalD, curFuel;
	cin >> totalD >> curFuel;

	// pretreatment
	for(int i = 0; i < stopNum;i++){
		stops[i].d = totalD - stops[i].d;
	}
	stops[stopNum].d = totalD;
	sort(stops.begin(),stops.end(),compare);

	int nextD = 0,curD = 0;
	int result = 0;
	priority_queue<int> stopsFuel;
	for(int i = 0; i <= stopNum;i++ ){
		nextD = stops[i].d - curD;
		while(curFuel - nextD < 0){
			if(stopsFuel.empty()){
				return -1;
			}
			else{
				curFuel += stopsFuel.top();
				stopsFuel.pop();
				result ++;
			}
		}
		curFuel -= nextD;
		stopsFuel.push(stops[i].f);
		curD += nextD;
	}
	return result;

}
int main()
{
	cout << solve();
	return 0;
}
