#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Interval{
    int start;
    int end;
    int efficiency;
}Interval;
bool compare(Interval i,Interval j){
    return i.end < j.end;
}

int main()
{
    int n, m, r;
    cin>>n>>m>>r;
    vector<Interval> list(m + 1);
    for(int i = 1; i <= m;i++){
        Interval item;
        cin>>item.start >> item.end >> item.efficiency;
        list[i] = item;
    }
    sort(list.begin() + 1,list.end(),compare);

    vector<int> pre(m + 1);
    for(int i = m; i > 0;i--){
        int j = i - 1;
        for(; j > 0 && (list[i].start - list[j].end) < r; j--);
        pre[i] = j;

    }


    vector<int> maxOutput(m + 1);
    maxOutput[0] = 0;

    for(int i = 1; i <= m;i++){
        maxOutput[i] = max(maxOutput[i - 1],maxOutput[pre[i]] + list[i].efficiency);
    }
    cout<<maxOutput[m]<<endl;

}
