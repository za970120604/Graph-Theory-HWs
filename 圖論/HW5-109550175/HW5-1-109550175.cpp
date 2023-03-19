#include<bits/stdc++.h>
#define int long long  
using namespace std;
int G[501][501] ;
int Graph[501][501] ;
void Floyd_Warshall(int n){
    for(int k = 1 ; k <= n; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(G[i][k] != LLONG_MAX && G[k][j] != LLONG_MAX){
                    if(G[i][j] > G[i][k] + G[k][j]){
                        G[i][j] = G[i][k] + G[k][j] ;
                    }
                }
            }
        }
    }
}

int Floyd_Warshall2(int n){
    int ans = LLONG_MAX ;
    for(int k = 1 ; k <= n; k++){
        for(int i = 1 ; i < k ; i++){
            for(int j = 1 ; j < i ; j++){
                if(i!= j && j != k && i != k && G[i][j] != LLONG_MAX && Graph[i][k] != LLONG_MAX && Graph[k][j] != LLONG_MAX){
                    ans = min(ans , G[i][j] + Graph[j][k] + Graph[k][i]) ;
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(G[i][k] != LLONG_MAX && G[k][j] != LLONG_MAX){
                    if(G[i][j] > G[i][k] + G[k][j]){
                        G[i][j] = G[i][k] + G[k][j] ;
                    }
                }
            }
        }
    }
    return ans ;
}

main(){
    for(int i = 0 ; i <= 500 ; i++){
        for(int j = 0 ; j <= 500 ; j++){
            G[i][j] = LLONG_MAX ;
        }
    }
    for(int i = 0 ; i <= 500 ; i++){
        G[i][i] = 0 ; 
    }
    int n , m ,type; 
    cin >> n >> m >> type ;
    if(type){
        for(int i = 1 ; i <= m ; i++){
            int u , v , w ; 
            cin >> u >> v >> w ; 
            G[u][v] = w ;
        }
        Floyd_Warshall(n) ;
        int ans = LLONG_MAX ; 
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(i != j && G[i][j] != LLONG_MAX && G[j][i] != LLONG_MAX){
                    ans = min(ans , G[i][j] + G[j][i]) ;
                }
            }
        }
        cout<<ans ; 
        cout<<'\n' ;
    }
    else{
        
        for(int i = 0 ; i <= 500 ; i++){
            for(int j = 0 ; j <= 500 ; j++){
                Graph[i][j] = LLONG_MAX ;
            }
        }
        for(int i = 0 ; i <= 500 ; i++){
            Graph[i][i] = 0 ; 
        }
        for(int i = 1 ; i <= m ; i++){
            int u , v , w ; 
            cin >> u >> v >> w ; 
            Graph[u][v] = w ; 
            Graph[v][u] = w ; 
            G[u][v] = w ;
            G[v][u] = w ;
        }
        
        int ans = Floyd_Warshall2(n) ;
        cout<<ans ; 
        cout<<'\n' ;
    }
    return 0 ;
}
