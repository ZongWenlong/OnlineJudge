#include <iostream>
#include <list>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int length;
    cin >> length;
    vector<char> chars(length);
    for(int i = 0; i < length; i++){
        char c;
        cin >> c;
        getchar();
        chars[i] = c;
    }

    int start = 0;
    int end = length - 1;
    int count = 0;
    while(start <= end){
        bool startFlag = true;
        for(int i = 0;start + i <= end;i++){
            if(chars[start + i] < chars[end - i]){
                break;
            }
            else if(chars[start + i] > chars[end - i]){
                startFlag = false;
                break;
            }
        }
        if(startFlag){
            cout<<chars[start];
            start++;
        }
        else{
            cout<<chars[end];
            end--;
        }
        count++;
        if(count % 80 == 0){
            cout<<endl;
        }

    }

    return 0;
}
