#include <iostream>
using namespace std;

int M = 1000000000;
int main()
{
    int N;
    cin >> N;
    unsigned long long* dp = new unsigned long long[N + 1];

    dp[1] = 1;
    for(int i = 2; i <= N; i ++){
        dp[i] = (i % 2 ? dp[i - 1] : dp[i - 1] + dp[i >> 1]) % M ;
    }
    cout<<dp[N];
}
