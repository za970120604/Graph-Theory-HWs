#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
const int MAXN = 200000 ;
vector<int>Graph[MAXN] ;
void Add(int u , int v ){
    Graph[u].push_back(v) ;
    Graph[v].push_back(u);
}
bool DFS(int start , int color , int* visited){
    bool res = true  ;
    visited[start] = color ; 
    for(int i = 0 ; i < Graph[start].size() ; i++){
        int next = Graph[start][i] ; 
        if(!visited[next] && !DFS(next , -color , visited)){
           res = false ; 
           break ; 
        }
        else if(visited[next] == color){
            res = false ; 
            break ; 
        }
    }
    return res ; 
}
bool isBipartite(int* visited , int n){
    bool res = true ; 
    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && DFS(i,1,visited) == false){
            res = false ; 
            break ; 
        }
    }
    return res ;
}
int main(){
    int n ; int m ;
    cin >> n >> m ;
    while(m--){
        int to ; int from ; 
        cin >> to >> from ; 
        Add(to-1 , from-1);
    }
    int visited[n] ; 
    memset(visited, 0 , sizeof(visited));
    if(isBipartite(visited , n)){
        int count = 1 ;
        int ccc = visited[0] ;  
        for(int i = 1 ; i < n ; i++){
            if(visited[i] == ccc){
                count++;
            }
        }
        cout<<count<<" "<<n-count<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0 ; 
}
