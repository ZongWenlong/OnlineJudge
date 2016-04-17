#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int d;
    int n;
    cin >> d >> n;
    while(d != -1){
        vector<int> armys(n);
        for(int i = 0; i < n;i ++){
            cin >> armys[i];
        }
        sort(armys.begin(),armys.end());

        int count = 1;
        int left = armys[0];
        int cur = armys[0];
        for(int i = 1; i < n ;i++){
            if(armys[i] - left > d){
                int temp = armys[i - 1];
                while(i < n && armys[i] - temp <= d ){
                    i++;
                }
                if(i < n){
                    count++;
                    left = armys[i];
                }

            }
        }
        cout<< count << endl;


        cin >> d >> n;
    }


    return 0;
}
