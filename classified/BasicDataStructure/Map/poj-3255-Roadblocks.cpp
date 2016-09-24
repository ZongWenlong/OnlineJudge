#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX_SIZE 20


/**
 * find the second shortest path
 */

struct Edge{
    int to,cost;
};
typedef pair<int,int> P; // first - cost, second - vertex id


int main ()
{
    int n,r;
    cin >> n >> r;
    vector<vector<Edge> > maps(n + 1);
    for(int i = 0,row; i < r;i++){
        Edge e;
        cin >> row >> e.to >> e.cost;
        maps[row].push_back(e);
    }

    vector<int> dist(n + 1,INT_MAX);
    vector<int> dist2(n + 1,INT_MAX);
    dist[1] = 0;
    dist2[1] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0,1));

    while(!que.enpty()){
        P p = que.top();
        que.pop;
        int v = p.second;
        int d = p.first;
        if(dist2[v] < d){
            continue;
        }
        else{
            for(int i = 0; i < maps[v].size();i++){
                Edge &e = maps[v][i];
                d2 = d + e.cost;
                if(dist[e.to] > d2){
                    swap(dist[e.to],d2);
                    que.push(P(dist[e.to],e.to));
                }
                if(dist2[e.to] > d2 && dist2[e.to] < d2){
                    dist2[e.to] = d2;
                    que.push(P(dist2[e.to],e.to));
                }
            }
        }
    }
    cout << dist2[n];

    return 0;
}
