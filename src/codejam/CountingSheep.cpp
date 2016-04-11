#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum; ){
        int n;
        cin >> n;
        if(n == 0){
            cout << "Case #" <<(++i) << ": INSOMNIA"<<endl;
        }
        else{
            int lastNum = 0;
            bool flag[10];
            memset(flag,false,sizeof(flag));
            int tureNum = 0;
            int cur = 0;
            while(tureNum < 10){
                cur = cur + n;

                //get each bit number
                int temp = cur;
                int quotient,reminder;
                do{
                    reminder = temp % 10;
                    if(flag[reminder] == false){
                        flag[reminder] = true;
                        tureNum ++;
                        lastNum = cur;
                    }
                    temp = temp / 10;
                }while(temp != 0 && tureNum < 10);
            }
            cout << "Case #" <<(++i) << ": " << lastNum <<endl;

        }
    }
    return 0;
}
