#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#define MOD 1000000007
using namespace std;


//大数组合数取模：以C(n,m)%p.其中p必须为质数
long long m,n;
long long p = 1000000007;
long long Pow(long long a,long long b) {
    long long ans=1;
    while(b) {
        if(b&1) {
            b--;
            ans=(ans*a)%p;
        } else {
            b/=2;
            a=(a*a)%p;
        }
    }
    return ans;
}
long long C(long long n,long long m) {
    if(n<m)
        return 0;
    long long ans=1;
    for(int i=1; i<=m; i++) {
        ans=ans*(((n-m+i)%p)*Pow(i,p-2)%p)%p;
    }
    return ans;
}
long long Lucas(long long n,long long m) {
    if(m==0)
        return 1;
    return Lucas(n/p,m/p)*C(n%p,m%p)%p;
}


int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y) != EOF){
        m = x - 2;
        n = x + y - 4;

        cout<<Lucas(n,m)<<endl;
    }

    return 0;
}
