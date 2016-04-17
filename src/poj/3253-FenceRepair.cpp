#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> cuts(num);
    for(int i = 0;i < num;i++){
        cin>>cuts[i];
    }

    int start = 0;
    long long total = 0;
    int temp;
    while(start < num - 1 ){
        if(cuts[start] > cuts[start + 1]){
            temp = cuts[start + 1];
            cuts[start + 1] = cuts[start];
            cuts[start] = temp;
        }

        int minI = start;
        int seMinI = start + 1;
        for(int j = start + 2; j < num;j++){
            if(cuts[j] < cuts[minI]){
                seMinI = minI;
                minI = j;
            }
            else if(cuts[j] < cuts[seMinI]){
                seMinI = j;
            }
        }
        int temp = cuts[minI] + cuts[seMinI];
        total+=temp;

        if(minI > seMinI){
            swap(minI,seMinI);
        }
        cuts[minI] = cuts[start];
        cuts[seMinI] = cuts[start + 1];
        cuts[start + 1] = temp;

        start++;

    }

    cout<<total<<endl;
    return 0;
}
