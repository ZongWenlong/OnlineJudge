#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
* dp[n][j] = 0
* dp[i][j] = dp[i+1][j]  (j < w[j])
* dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - w[i]] + v[i])  (j >= w[j])
**/

#define MAX_N 102
#define MAX_W 10002

int w[MAX_N];
int v[MAX_N];
int dp[MAX_N][MAX_W];

int main()
{
    int num;
    int W;
    cin >> num;

    for(int i = 0;i < num;i++){
        cin >> w[i] >> v[i];
    }
    cin >> W;

    dp[num][W] = 0;
    for(int i = num - 1; i >= 0;i--){
        for(int j = 0;j <= W;j++){
            if(j < w[i]){
                dp[i][j] = dp[i + 1][j];
            }
            else{
                dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }

    cout<<dp[0][W]<<endl;
    return 0;
}
