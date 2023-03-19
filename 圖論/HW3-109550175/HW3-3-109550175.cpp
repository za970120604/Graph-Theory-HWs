#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
const int MAXN = 400000 ;
vector<int>G[MAXN] ;
int in[MAXN]; //store the discovered time
int low[MAXN] ; //store the least time a descendent of a node {index == node id} is discovered
int visited[MAXN] ;
int timer = 0 ;
int ans = 0 ; 
void dfs(int node , int parent){
    visited[node] = 1 ;
    low[node] = in[node] = timer ;
    timer++ ;
    for(int i = 0 ; i < G[node].size() ; i++){
        int temp = G[node][i] ;
        if(temp == parent){ //multi-edge
            continue ;
        }
        else if(visited[temp]){ //temp is the "ancestor" of node , but not parent of node
            low[node] = min(low[node] , in[temp]) ;
        }
        else if(!visited[temp]){
            dfs(temp , node) ;
            if(low[temp] > in[node]){ //bridge edge 
                ans += 1 ;
            }
            low[node] = min(low[node] , low[temp]) ;
        }
    }
}
int main(){
    for(int i = 0 ; i < MAXN ; i++){
        in[i] = MAXN ;
        low[i] = MAXN ;
    }
    memset(visited,0,sizeof(visited)) ;
    int N ; int M ; 
    cin >> N >> M ;
    while(M--){
        int u , v ;
        cin >> u>> v ;
        G[u].push_back(v) ; 
        G[v].push_back(u) ;
    }
    dfs(1,-1) ;
    cout<<ans;
    cout<<'\n' ;
    return 0 ;  
}
