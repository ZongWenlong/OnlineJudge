#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

void getNextNum(vector<int> &cur){

    for(int i = 1; i < cur.size() - 1;i++){
        if(cur[i] == 0){
            cur[i] = 1;
            break;
        }
        else{
            cur[i] = 0;
        }
    }
}

long long getNumBaseI(vector<int> bitNum,int baseI){
    long long numBaseI = 0;
    int pow = 1;
    for(int i = 0; i < bitNum.size();i++,pow =  pow * baseI){
        numBaseI = numBaseI + bitNum[i] * pow;
    }
    return numBaseI;
}

long long isPrime(long long num){
    if(num <= 3){
        return -1;
    }
    else{
        long long endFlag = (long long)sqrt(num) + 1;
        for(long long i = 2; i < endFlag;i++){
            if(num % i == 0){
                return i;
            }
        }

        return -1;
    }
}
int main()
{
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum; ){
        int n,j;
        cin >> n>>j;
        cout << "Case #" <<(++i) << ":" <<endl;

        vector<int> bitNums(n,0);
        bitNums[0] = 1;
        bitNums[n - 1] = 1;
        long long diverBase10[11];
        for(int resultNum = 0;resultNum < j;){
            getNextNum(bitNums);
            bool findFlag = true;
            for(int baseI = 2; baseI <= 10;baseI++){
                diverBase10[baseI] = isPrime(getNumBaseI(bitNums,baseI));
                if(diverBase10[baseI] ==  -1){
                    findFlag = false;
                    break;
                }
            }

            if(findFlag == true){
                for(int bitI = bitNums.size() - 1; bitI >= 0;bitI--){
                    cout<<bitNums[bitI];
                }

                for(int diverI = 2;diverI <= 10;diverI++){
                    cout<<" "<<diverBase10[diverI];
                }
                cout<<endl;
                resultNum++;
            }
        }
    }
    return 0;
}


