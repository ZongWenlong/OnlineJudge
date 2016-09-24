#include <iostream>
#include <string>
using namespace std;
int main()
{
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum; ){
        int sMax;
        cin >> sMax;
        string sNum;
        cin >> sNum;
        int curNum = 0;
        int needNum = 0;
        int sCurNum = 0;
        for(int i = 0;i < sNum.length();i++){
            sCurNum = sNum[i] - '0';
            if(sCurNum > 0){
                if(curNum >= i){
                    curNum = curNum + sCurNum;
                }
                else{
                    needNum = needNum + i - curNum;
                    curNum = curNum + i - curNum + sCurNum;
                }
            }

        }

        cout << "Case #" <<(++i) << ": "<<needNum<<endl;
    }
    return 0;
}
