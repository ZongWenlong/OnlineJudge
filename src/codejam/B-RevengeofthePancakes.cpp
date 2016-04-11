#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int getMinFlipNum(vector<bool> pancakes,int start)
{
    int flipCount = 0;
    for(int i = start;i < pancakes.size();){
        if(pancakes[i] == true){
            i++;
        }
        else{
            int end = pancakes.size() - 1;
            if(pancakes[end]== true){
                flipCount ++;
                while(end > i && pancakes[end]== true){
                    pancakes[end] = false;
                    end--;
                }
            }

            flipCount ++;
            int left,right;
            for(left = i,right = pancakes.size() - 1;left < right;left++,right--){
                int temp = !pancakes[right];
                pancakes[right] = !pancakes[left];
                pancakes[left] = temp;
            }
            if(left == right){
                pancakes[left] = !pancakes[left];
            }
            flipCount = flipCount + getMinFlipNum(pancakes,i + 1);
            break;
        }
    }
    return flipCount;
}
int main()
{
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum; ){
        string stackStr;
        cin >> stackStr;
        vector<bool> pancakes(stackStr.length());
        for(int k =0,j = stackStr.length() - 1; j >= 0;j--,k++){
            if(stackStr[j] == '+'){
                pancakes[k] = true;
            }
            else{
                pancakes[k] = false;
            }
        }
        cout << "Case #" <<(++i) << ": " << getMinFlipNum(pancakes,0) <<endl;


    }
    return 0;
}


