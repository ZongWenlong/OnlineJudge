#include <iostream>

using namespace std;


#define N_MAX 101
#define MAX 100001

int a[MAX];
int m[MAX];

bool dp[N_MAX][MAX];

void dpSolveVerson1(int n,int K)
{
    dp[0][0] = true;
    for(int i = 0; i < n;i++){
        for(int j = 0; j <= K;j++){
            for(int k = 0; k <= m[i] && k * a[i] <= j; k++){
                dp[i + 1][j] = dp[i][j - k * a[i]];
                if(dp[i + 1][j] == true){
                    break;
                }
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n;i++){
        cin >> m[i];
    }

    int K;
    cin >> K;

    dpSolveVerson1(n,K);
    cout<<dp[n][K];

}
