#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

long long dp[(1<<20)][20];
int main(){
    int n , m , k ;
    cin >> n >> m >> k ;
    long long G[n][n] ;
    
    int color[n] ;
    for(int i = 0 ; i < n ; i++){
        int c ; cin >> c ; 
        c -= 1 ;
        color[i] = c ;  
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            G[i][j] = INT_MAX ; 
        }
    }
    while(m--){
        long long  u , v , w ;
        cin >> u >> v >> w ; 
        G[u-1][v-1] = w ; 
        G[v-1][u-1] = w ;
    }
    
    for(int i = 0 ; i < n ; i++){
        G[i][i] = 0 ; 
    }
    
    for(int inter = 0 ; inter < n ; inter++){
        for(int i = 0 ; i < n ;  i++){
            for(int j = 0 ; j < n ; j++){
                if(G[i][inter] != INT_MAX && G[inter][j] != INT_MAX){
                    G[i][j] = min(G[i][inter]+G[inter][j] , G[i][j]) ;
                }
            }
        }
    }
    
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1e9;
        }
    }
    
    for (int i = 0; i < n; i++) dp[(1 << i)][i] = 0;
    
    for(int mask = 1 ; mask <= (1<<n)-1 ; mask++){
        for(int last = 0 ; last < n ; last++){
            if(mask&(1<<last) == 0){
                continue ;
            }
            for (int j = 0; j < n; j++) {
                dp[(mask | (1 << j))][j] = min(dp[(mask | (1 << j))][j], dp[mask][last] + G[last][j]);
            } 
        }  
    }
    
    long long ans = 1e9;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            int All = 0;
            for (int z = 0; z < n; z++) {
                if ((1 << z) & i) All = (All | (1 << color[z]));
            }
            if (All == (1<<k)-1) ans = min(ans, dp[i][j]);
        }
    }
    cout<< ans;
    cout<<'\n' ;
    return 0 ;
} 
