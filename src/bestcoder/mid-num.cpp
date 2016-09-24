#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>

#define DEFAULT 1

using namespace std;

typedef struct{
    int value;
    int pos;
}Num;
bool compare(Num a,Num b)
{
  return a.value < b.value ;
}



int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        vector<Num> nums(n);
        vector<int> rightUp(n); //右边递增的终点
        vector<int> leftUp(n,1);  //左边递减的个数
        vector<int> result(n);
        for(int i = 0; i < n;i++){
            scanf("%d",&nums[i].value);
            nums[i].pos = i;
        }

        sort(nums.begin(),nums.end(),compare);


        if(n > 0){
            //初始化 rightUp[0]
            rightUp[0] = 0;
            result[nums[0].pos] = 1;
            for(int i = 1;i < n;i++){
                if(nums[i] > nums[i - 1]){
                    rightUp[0] = i;
                }
                else{
                    break;
                }
            }
            for(int i = 1;i < n;i++){
                if(i <= rightUp[i - 1]){
                    leftUp[i] = leftUp[i - 1] + 1;
                    rightUp[i] = rightUp[i - 1];
                    printf(" %d",min(leftUp[i],rightUp[i] - i + 1));
                }
                else{
                    cout<<" " <<DEFAULT;
                    rightUp[i] = i;
                    for(int j = i + 1;j < n;j++){
                        if(nums[j] > nums[j - 1]){
                            rightUp[i] = j;
                        }
                        else{
                            break;
                        }
                    }
                    // leftup有初始化，所以不用再处理
                }
            }
        }
        printf("\n");
    }



    return 0;
}
