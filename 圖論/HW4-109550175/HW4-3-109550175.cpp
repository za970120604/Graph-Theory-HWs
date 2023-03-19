#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN = 2000000 ;
vector< pair<int,int> >G[MAXN] ;
vector<int>visited(MAXN) ;
int ans = 0 ;
void DFS(int root , int prev_edge){
    visited[root] = 1 ; 
    for(auto child : G[root]){
        if(!visited[child.first] && child.second > prev_edge){
            ans += 1 ; 
            DFS(child.first , child.second) ;
        }
    }
}
main(){
    int n ; cin >> n ; 
    for(int i = 1 ; i<=n-1 ; i++){
        int u , v , w; cin >> u >> v >>w;
        G[u].push_back({v,w}) ;
        G[v].push_back({u,w}) ;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int i = 1 ; i <= n ; i++) visited[i] = 0 ;  
        DFS(i , -1) ;
    }
    cout<<ans ; 
    cout<<'\n' ;
    return 0 ;
}
