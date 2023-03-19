#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 5e5+5 ;

struct Edge {
    int id ; 
    long long int w;
    bool operator < (const Edge &cmp) const {
        return cmp.w < w;
    }
};

vector< pair<int,int> >G[MAXN];
vector<long long>cost(MAXN, -1);
long long val[MAXN];
priority_queue<Edge>pq;

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1 ; i <= n; i++) {
        cin >> val[i];
        pq.push({i , val[i]});
    }
    
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    while (!pq.empty()) {
        Edge temp = pq.top();
        pq.pop();
        if (cost[temp.id] != -1){
            continue;
        }
        else{
            cost[temp.id] = temp.w;
            int j = G[temp.id].size() ;
            for (int i = 0 ; i < j ; i++) {
                if (cost[G[temp.id][i].first] == -1) {
                    pq.push({G[temp.id][i].first , G[temp.id][i].second + temp.w});
                } 
            }
        }
    }
    for (int i = 1 ; i <= n; i++) {
        cout << cost[i] << " ";
    }
    cout<<'\n' ;
    return 0 ;
}
