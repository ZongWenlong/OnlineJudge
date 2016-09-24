
/**
 * common method
 */
#define MAX_V 101 // MAX_V = Real vertex number + 1
int cost[MAX_V][MAX_V];
bool used[MAX_V];
int dist[MAX_V];
int n; // vertext number
int s; // start id

void dijkstra()
{
    fill(used,used + MAX_V,false);
    fill(dist,dist + MAX_V,INT_MAX);
    dis[s] = 0;
    
    while(true){
        int v = -1;
        // find mininum distince vertex
        for(int i = 0; i < n;i++){
            if(!used[i] && (v == -1 || dist[i] < dist[v])){
                v = i;
            }
        }

        if(v == -1){
            return;
        }
        else{
            used[v] = true;
            for(int i = 0; i < n;i++){
                if(used[i] == false){
                    dist[i] = min(dist[i],dist[v] + cost[v][i]);
                } 
            }
        }
        
    }
}


/**
 * priority queue
 */

struct Edge{
    int to, cost;
}
typedef pair<int,int> P //first - mininum distance, second - vertex ID
vector<vector<Edge> > G;
int dist[MAX_V];
int s; //start vertex ID

void dijkstra()
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist,dist + MAX_V,INT_MAX);
    que.push(P(0,s));
    
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        // 因为里边会有参与的d所以此处加以过滤。比如有两个d[0]
        if(d[v] < p.first){
            continue;
        }
        for(int i = 0; i < G[v].size();i++){
            edge e = G[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
