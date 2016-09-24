#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    map<string,int> nameMap;
    for(int i = 0; i < caseNum; i++){
        string name;
        cin >> name;
        sort(name.begin(),name.end());

        int num = nameMap[name];

        cout << num <<endl;
        nameMap[name]++;


    }
    return 0;
}

