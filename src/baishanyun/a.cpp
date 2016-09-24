#include <iostream>

using namespace std;


int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T;i++){
        int a,b,d,n;
        cin >> a >> b >> d >> n;
        int mulTemp = a * b;
        if(mulTemp < 10){
            if(d == mulTemp){
                cout<<n<<"\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else if(n  < 5){
            int an = 0;
            for(int j = 0; j < n;j++){
                an = an * 10 + a;
            }
            mulTemp = an * b;
            int count = 0;
            for(int mod;mulTemp > 0;mulTemp = mulTemp / 10){
                mod = mulTemp % 10;
                if(mod == d){
                    count ++;
                }
            }
            cout<<count<<"\n";
        }
        else{
            int an2 = 0;
            for(int j = 0; j < 2;j++){
                an2 = an2 * 10 + a;
            }
            int an3 = an2 * 10 + a;

            int mul2 = an2 * b;
            int mul3 = an3 * b;
            mul3 = mul3 / 100;
            int dupNum = mul3 % 10;
            int count = 0;
            if(d == dupNum){
                count = n - 2;
            }
            for(int mod;mul2 > 0;mul2 = mul2 / 10){
                mod = mul2 % 10;
                if(mod == d){
                    count ++;
                }
            }
            cout<<count<<"\n";
        }
    }
    return 0;
}
