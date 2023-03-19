#include <iostream>
#include <vector>
#include <memory.h> 
using namespace std;
const int MAXN = 200000;
vector<int>G[MAXN] ; 
void add(int u , int v){
    G[u-1].push_back(v-1) ;
    G[v-1].push_back(u-1) ;
}
int target = -1 ; 
int max_for_random = 0 ; int max_for_final = 0 ; 
void DFS(int start , int* visited , int len , int flag){
    visited[start] = 1 ; 
    for(int  i = 0 ; i < G[start].size() ; i++){
        if(!visited[G[start][i]]){
            DFS(G[start][i] , visited , len+1 , flag) ;
            if(flag){
                if(max_for_random <= len + 1){
                    max_for_random = len + 1 ; 
                    target = G[start][i] ;
                } 
            }
            else{
                max_for_final = max(max_for_final , len+1) ;
            }
        }
    }
}
int main(){
    int N ; 
    cin >> N ;
    int k = N-1 ;  
    while(k--){
        int u ; int v ; 
        cin >> u >> v ;
        add(u,v) ;
    }
    if(N==1){
        cout<<0;
        cout<<'\n' ;
    }
    else{
        int visited[N] ; 
        memset(visited , 0 , sizeof(visited)) ;
        DFS(0 , visited , 0 , 1);
        memset(visited , 0 , sizeof(visited)) ;
        DFS(target , visited , 0 , 0 );
        cout<<max_for_final;
        cout<<'\n' ; 
    }
    return 0 ; 
}
