#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 1002
#define MAX_M 1002

int dp[MAX_N][MAX_M];

int main()
{
    int n,m;
    cin >> n >> m;

    string nStr,mStr;
    cin >> nStr >> mStr;

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(nStr[i] == mStr[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1],dp[i + 1][j]);
            }
        }
    }

    cout<<dp[n][m]<<endl;
    return 0;
}
