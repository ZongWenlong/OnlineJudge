
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int> > dp(N);
    int maxVale = 0;
    for(int i = 0; i < N;i++){
        vector<int> dpLine(i + 1);
        dp[i] = dpLine;
        for(int j = 0,cur = 0; j <= i;j++){
            cin >> cur;
            if(i == 0){
                dp[i][j] = cur;
            }
            else{
                if(j == 0){
                    dp[i][j] = dp[i - 1][j] + cur;
                }
                else if(j == i){
                    dp[i][j] = dp[i - 1][j - 1] + cur;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j]) + cur;
                }
                if(dp[i][j] > maxVale){
                    maxVale = dp[i][j];
                }
            }

        }
    }

    cout<<maxVale<<endl;
}
