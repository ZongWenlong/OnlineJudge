#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define T_MAX 1002
#define W_MAX 32
int dp[T_MAX][W_MAX];

int nums[T_MAX];

int main()
{
    int T,W;
    cin >> T >> W;

    for(int i = 1; i <= T;i++ ){
        cin >> nums[i];
        nums[i]--;
    }

    dp[0][0] = 0;
    for(int i = 1;i <= T;i++){
        dp[i][0] = dp[i - 1][0] + !nums[i];

        for(int j = 1; j <= W;j++){
            int temp1,temp2;
            if(j % 2 == 0){
                temp1 = dp[i - 1][j] + !nums[i];
                temp2 = dp[i - 1][j - 1] + nums[i];
            }
            else{
                temp1 = dp[i - 1][j] + nums[i];
                temp2 = dp[i - 1][j - 1] + !nums[i];
            }
            dp[i][j] = max(temp1,temp2);
        }
    }
    int maxValue = 0;
    for(int i = 0;i <= W;i++){
        maxValue = max(dp[T][i],maxValue);
    }
    cout<<maxValue<<endl;
    return 0;
}
