#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

typedef struct {
    int leftNum;
    int position;
} ParenLeft;

int main()
{
    int caseNum;
	cin >> caseNum;

	for(int i = 0; i < caseNum;i++){
        int seqSize;
        cin >> seqSize;
        stack<ParenLeft> parenleft;
        int pre,cur;
        cin >> pre;
        cout<< 1 <<" ";
        if(pre > 1){
            ParenLeft pointer;
            pointer.leftNum = pre - 1;
            pointer.position = 0;
            parenleft.push(pointer);
        }
        for(int j = 1;j < seqSize;j++){
            cin >> cur;
            int incre = cur - pre;
            if(incre > 0){
                cout<< 1 <<" ";
                if(incre > 1){
                    ParenLeft pointer;
                    pointer.leftNum = incre - 1;
                    pointer.position = j;
                    parenleft.push(pointer);
                }
            }
            else{
                ParenLeft pointer = parenleft.top();
                parenleft.pop();
                cout <<(j - pointer.position + 1) << " ";
                pointer.leftNum--;
                if(pointer.leftNum > 0){
                    parenleft.push(pointer);
                }
            }
            pre = cur;
        }

        cout<<endl;

	}



	return 0;
}
