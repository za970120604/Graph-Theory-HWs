#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 21 ;
vector<int>G[MAXN] ; 
int ans = 0 ; 
int C[MAXN] ; 
bool check(int index , int color_to_draw){
    if(G[index].size() == 0){
        return true ; 
    }
    for(auto neigh : G[index]){
        if(C[neigh] == color_to_draw){
            return false ;
        }
    }
    return true ; 
}
void Coloring(int index , int num){
    if(index > num){
//        for(int i = 1 ; i <= num ; i++){
//            cout<<C[i]<<"  " ;
//        }
        ans += 1 ; 
//        cout<<endl;
        return ;
    }
    for(int color = 1 ; color <= 3 ; color++){
        if(check(index , color)){
            C[index] = color ; 
            Coloring(index + 1 , num) ; 
            C[index] = 0 ;     
        }
    }
}
main(){
    memset(C , 0 , sizeof(C)) ; 
    int n , m ; 
    cin >> n >> m ; 
    for(int i = 0 ; i < m ; i++){
        int u , v; 
        cin >> u >> v ; 
        G[u].push_back(v) ; 
        G[v].push_back(u) ;
    }
    if(m == 0){
        cout<<(int)pow(3,n)<<'\n' ;
    }
    else{
        Coloring(1 , n) ;
        cout<<ans<<'\n' ;
    }
}


