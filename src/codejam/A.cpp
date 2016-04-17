#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum; ){
        string str;
        cin >> str;
        list<char> strList;

        strList.push_back(str[0]);
        for(int j = 1;j < str.length();j++){
            if(strList.front() <= str[j]){
                strList.push_front(str[j]);
            }
            else{
                strList.push_back(str[j]);
            }
        }

        cout << "Case #" <<(++i) << ": ";
        for(list<char>::iterator it = strList.begin();it != strList.end();it++){
            cout<<*it;
        }
        cout<<endl;

    }
    return 0;
}
