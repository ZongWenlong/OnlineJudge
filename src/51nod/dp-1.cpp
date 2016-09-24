#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string a;
    string b;
    cin >> a >> b;

    vector<vector<int> > dp(a.size() + 1);

    vector<int> dpRow(b.size() + 1);
    dp[0] = dpRow;
    for(int i = 0; i <= b.size();i++ ){
        dp[0][i] = i;
    }

    for(int i = 1; i <= a.size();i++){
        vector<int> dpRow(b.size() + 1);
        dp[i] = dpRow;
        dp[i][0] = i;
    }
    int minTemp;
    for(int i = 0; i < a.size();i++){
        for(int j = 0; j < b.size();j++){
            if(a[i] == b[j]){
                dp[i + 1][j + 1] = dp[i][j];
            }
            else{
                minTemp = min(dp[i][j] + 1,dp[i][j + 1] + 1);
                dp[i + 1][j + 1] = min(minTemp,dp[i + 1][j] + 1);
            }
        }
    }

    cout<<dp[a.size()][b.size()]<<endl;
    return 0;
}
