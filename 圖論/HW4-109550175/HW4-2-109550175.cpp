#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 200001 ;
int capacity[4500][4500] ;
vector<int>adj[MAXN];
int parent[MAXN] ;
int n , m , k ;
long long BFS(int src , int sink){
    memset(parent , 0 , sizeof(parent)) ;
    parent[src] = -1;
//    for(int i = 1 ; i <= n+m+2 ; i++){
//        cout<<parent[i]<<" " ; 
//    }
//    cout<<endl;
    queue< pair<int, int> > q;
    q.push({src , INT_MAX});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (auto next : adj[cur]){
            if (parent[next] == 0 && capacity[cur][next] > 0) {
//                cout<<"remain flow from "<<cur<<" to "<<next<<endl; 
                parent[next] = cur ; 
                long long new_flow = min(flow, capacity[cur][next]);
                if (next == sink){
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

long long maxflow(int src , int sink) {
    long long maxflow = 0;
    long long new_flow;
    while (1) {
        new_flow = BFS(src , sink) ;
        if(new_flow == 0){
            break ;
        }
        maxflow += new_flow;
        int cur = sink;
        while (cur != src) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
//            cout<<prev<<" to "<<cur<<" increase flow by "<<new_flow<<endl;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return maxflow;
}
int main(){
    cin >> n >> m >> k ; 
    int src = n+m+1 ; int sink = n+m+2 ;
    memset(capacity , 0 , sizeof(capacity)) ;
    for(int i = 1 ; i <= n ; i++){
        int t ; cin >> t ; 
        capacity[src][i] = t ;
        adj[src].push_back(i) ;
        adj[i].push_back(src) ;
    }
    for(int i = 1 ; i <= m ; i++){
        int t ; cin >> t ; 
        capacity[n+i][sink] = t ;
        adj[n+i].push_back(sink) ;
        adj[sink].push_back(n+i) ;
    }
    for(int i = 1 ; i <= k ; i++){
        int xi , yi ; cin >> xi >> yi ;
        capacity[xi][n+yi] = 1 ; 
        adj[xi].push_back(n+yi) ;
        adj[n+yi].push_back(xi) ;
    }
//    for(int i = 1 ; i <= n+m+2 ; i++){
//        for(int j = 0 ; j < adj[i].size() ; j++){
//            cout<<adj[i][j]<<" ";
//        }
//        cout<<endl; 
//    }
    int ans = maxflow(src , sink) ; 
    cout<<ans;
    cout<<'\n' ;
    return 0 ;
}


