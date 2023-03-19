#include<bits/stdc++.h> 
using namespace std;
const int MAXN = 200001 ;
struct Situation{
    long long exclude ; 
    long long include ; 
};
vector<int>G[MAXN] ;
int visited[MAXN] ;
long long cost[MAXN];
vector<Situation>dp(MAXN) ;
void DFS(int src , int par){
    visited[src] = 1 ; 
    for(auto child : G[src]){
        if(!visited[child]){
            DFS(child , src) ;
        }
    }
    //handle leaf node
    if(G[src].size() == 1 && G[src][0] == par){
        dp[src].include = cost[src] ;
        dp[src].exclude = 0 ; 
        return ;
    }
    //handle the case include this src node ;
    long long combination = cost[src]; //src 這個點自己要加進去 
    for(auto child : G[src]){
        if(child != par){
            combination += min(dp[child].include , dp[child].exclude) ; 
        }
    }
    dp[src].include = combination ; 
    //handle the case exclude this src node ; 
    long long sum = 0 ; 
    for(auto child : G[src]){
        if(child != par){
            sum += dp[child].include ; 
        }
    }
    dp[src].exclude = sum ; 
}
int main(){
    int N ; cin >> N ; 
    memset(visited , 0 , sizeof(visited)) ;
    for(int i = 1 ; i <= N ; i++){
        long long c ; cin >> c ;
        cost[i] = c ; 
    }
    for(int i = 1 ; i <= N-1 ; i++){
        int parent ; int child ; 
        cin >> parent >> child ; 
        G[parent].push_back(child) ; 
        G[child].push_back(parent) ;
    }
    DFS(1 , -1) ;
    long long ans1 = min(dp[1].exclude , dp[1].include) ;
    
    memset(visited , 0 , sizeof(visited)) ;
    for(int i = 1 ; i <= N ; i++){
        cost[i] = 1 ;
    }
    dp.clear() ;
    
    DFS(1 , -1) ;
    long long ans2 = min(dp[1].exclude , dp[1].include) ;
    
    cout<<ans1<<" "<<ans2<<'\n'; 
    return 0 ;
}
