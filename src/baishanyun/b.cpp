#include <iostream>

using namespace std;

int dp[2000][2000];

int main()
{
    int N;
    cin >> N;

    dp[0][0] = 1;
    dp[1][1] = 1;

    for(int n = 2; n <= N;n++){
        for(int h = 2; h <= n;h++){
            for(int k = 1; k <= n;k++){
                dp[n][h] = dp[n][h] + (dp[k - 1][h - 1] % 1000000007) * (dp[n - k][h - 1] % 1000000007) +
                                      (dp[k - 1][h - 1] % 1000000007) * (dp[n - k][h - 2] % 1000000007) +
                                      (dp[k - 1][h - 2] % 1000000007) * (dp[n - k][h - 1] % 1000000007);
            }
        }
    }

    long long total = 0;
    for(int i = 0;i <= N;i++){
        total = total % 1000000007 + dp[N][i] % 1000000007 ;
    }

    cout<<total<<endl;

    return 0;
}
