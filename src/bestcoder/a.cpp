#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LEN_MAX 100000;

int getSumUtil(vector<int> &tree, int left, int right, int qLeft,int qRight,int index)
{
    if (qLeft <= left && qRight >= right)
        return tree[index];

    if (right < qLeft || left > qRight)
        return 1;

    // 如果节点的线段与区间的一部分有交集
    int mid = left + (right -left) / 2;
    return getSumUtil(tree, left, mid, qLeft, qRight, 2*index+1) *
           getSumUtil(tree, mid+1, right, qLeft, qRight, 2*index+2) % 9973;
}

int getSum(vector<int> &tree, int size, int qLeft, int qRight)
{
    return getSumUtil(tree, 0, size - 1, qLeft, qRight, 0);
}


int initTree(string &str,vector<int> &tree,int left,int right,int index){
    if(left == right){
        tree[index] = str[left] - 28;
        return tree[index];
    }
    int mid = left + (right -left) / 2;
    tree[index] = initTree(str,tree,left,mid,index * 2 + 1) * initTree(str,tree,mid + 1,right,index * 2 + 2) % 9973;
    return tree[index];
}

int main()
{
    int caseNum;
    while(cin >> caseNum){
        string str;
        cin >> str;

        vector<int> mul(str.size() - 1);
        mul[0] = str[0] - 28;
        for(int i = 1; i < str.size();i++){
            mul[i] = mul[i - 1] * (str[i]-28) % 9973;
        }
        for(int i = 0; i < caseNum; i++){
            int left,right;

            cin >> left >> right;
            left --;
            right --;
            for(int k = 0; true;k++){
                if((k * 9973 + mul[right]) % mul[left] == 0){
                    cout << (k * 9973 + mul[right]) / mul[left]<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
