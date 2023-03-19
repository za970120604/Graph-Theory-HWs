#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 200005 ;
vector<int>G[MAXN] ;
int visited[MAXN] ;
int dp[MAXN] ;
void DFS(int root){
    visited[root] = 1 ;
    for(int i = 0 ; i < G[root].size() ; i++){
        if(!visited[G[root][i]]){
            DFS(G[root][i]) ;
        }
    }
    if(G[root].size() == 0){
        dp[root] = 1 ;
    }
    else{
        int multi = 1 ; 
        for(int i = 0 ; i < G[root].size() ; i++){
            multi = (multi%1000000007)*(dp[G[root][i]]%1000000007+(1%1000000007))%1000000007;
        }
        dp[root] = multi%1000000007 ;
    }
}
main(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n-1 ; i++){
        int u , v;  cin >> u >> v; 
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    memset(dp , 0 , sizeof(dp)) ;
    memset(visited , 0 , sizeof(visited)) ;
    DFS(1) ;
    int ans = 0 ; 
    for(int i = 1 ; i <= n ; i++){
        ans += dp[i]%1000000007 ;
    }
    cout<<ans%1000000007;
    cout<<'\n' ;
}
