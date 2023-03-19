#include <iostream>
#include <vector> 
#include <memory.h> //WA
using namespace std;
const int MAXN = 2000001 ;
vector<int>G[MAXN] ;
int visited[MAXN] ;
int degree[MAXN] ;
void dfs(int start){
    visited[start] = 1 ; 
    for(int i = 0 ; i < G[start].size() ; i++){
        if(!visited[G[start][i]]){
            dfs(G[start][i]) ;
        }
    }
}
int main(){
    int N , M ;  
    cin >> N >> M;
    memset(visited , 0 , sizeof(visited)) ;
    memset(degree , 0 , sizeof(degree)) ;
    for(int i = 0 ; i < M ; i++){
        int u , v ; 
        cin >> u >> v ;
        G[u].push_back(v) ; 
        G[v].push_back(u) ;
        degree[u]++ ;
        degree[v]++ ;
    }
    int cnt = 0 ;
    int index1 = 1 ; 
    for(int i = 1 ; i <= N ; i++){
        if(degree[i]){
            index1 = i ;
        }
        if(degree[i]%2){
            cnt += 1 ; 
        }
    }
    if((cnt < 2 && cnt != 0 )|| cnt > 2){
        cout<<"NO";
        cout<<'\n' ;
    }
    else if(cnt == 2 || cnt == 0){
        dfs(index1) ;
        int res = 1 ;
        for(int i = 1; i <= N ; i++){
            if(degree[i] && !visited[i]){
                cout<<"NO" ;
                cout<<'\n' ;
                res = 0 ;
                break ; 
            }
        }
        if(res){
            cout<<"YES";
            cout<<'\n' ; 
        }
    }
    return 0 ; 
}

