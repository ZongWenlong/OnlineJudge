#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    int caseNum;
    scanf("%d",&caseNum);
    int x;
    int m;
    int k,c;
    for(int i = 1 ; i <= caseNum;i++){
        scanf("%d %d %d %d",&x,&m,&k,&c);

        int preMod = x % k;
        int totalMod = preMod;
        int tenMod = 10 % k;
        int temp;
        for(int j = 1;j < m;j++){
            preMod = (preMod * tenMod) % k;
            totalMod = (totalMod + preMod) % k;
        }

        printf("Case #%d:\n",i);
        if(totalMod == c){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
