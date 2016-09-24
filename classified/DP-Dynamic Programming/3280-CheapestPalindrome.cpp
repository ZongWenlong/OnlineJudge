#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
* if str[i] == str[j], then dp[i][j] = dp[i + 1][j - 1];
* else
*    dp[i][j] = min(dp[i][j],dp[i + 1][j] + cost[str[i]]);
*    dp[i][j] = min(dp[i][j],dp[i][j - 1] + cost[str[j]]);
*
**/
int main()
{
    int N,M;
    cin >> N >> M;
    string str;
    cin >> str;

    vector<int> add(26);
    vector<vector<int> > dp(M);
    for(int i = 0; i < M;i++){
        vector<int> row(M,0);
        dp[i] = row;
    }
    for(int i = 0; i < N; i++){
        char key;
        int addCost,delCost;
        cin >> key >> addCost >> delCost;
        add[key - 'a'] = min(addCost,delCost);
    }

    for(int i = M - 1;i >= 0;i--){
        for(int j = i + 1; j < M;j++){
            dp[i][j] = INT_MAX;
            if(str[i] == str[j]){
                dp[i][j] = dp[ i + 1][j - 1];
            }
            else{
                dp[i][j] = min(dp[i][j],dp[i + 1][j] + add[str[i] - 'a']);
                dp[i][j] = min(dp[i][j],dp[i][j - 1] + add[str[j] - 'a']);
            }
        }
    }
    cout << dp[0][M - 1];
    return 0;
}
