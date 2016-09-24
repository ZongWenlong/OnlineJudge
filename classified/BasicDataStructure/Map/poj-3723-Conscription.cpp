#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
#define TOTAL_COST 10000
#define CAL_OVER 2
#define CAL_NO 1
#define NOT_USE 0

struct Edge{
    int from, to, cost;
};
bool comp(const Edge& edge1,const Edge& edge2){
    return edge1.cost < edge2.cost;
}


int main ()
{
    int caseNum;
    cin >> caseNum;
    for(int i = 0; i < caseNum;i++){
        int n,m,r;
        cin >> n >> m >>r;
        vector<Edge> edges(r);
        for(int j = 0;j < r;j++){
            Edge e;
            cin >> e.from >> e.to >> e.cost;
            e.to = e.to + n;
            e.cost = TOTAL_COST - e.cost;
            edges[j] = e;
        }

        sort(edges.begin(),edges.end(),comp);
        vector<bool> used(n + m,false);
        int total = 0;

        for(vector<Edge>::iterator it = edges.begin();it != edges.end();it++){
            if(used[(*it).from] == false){
                if(used[(*it).to]) == false){
                    used[(*it).from] == true;
                    used[(*it).to] == true;
                    total = total + TOTAL_COST + (*it).cost;
                }
                else{
                    used[(*it).from] == true;
                    total = total + (*it).cost;
                }
            } 
            else{
                if(used[(*it).to]) == false){
                    used[(*it).to] == true;
                    total = total + (*it).cost;
                }
            }
        }

        cout << total<<endl;

    }

    return 0;
}
