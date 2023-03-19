#include <iostream>
#include <vector> 
#include <memory.h>
#include <algorithm> 
using namespace std;
struct Edge{
    int id ; 
    int u ; 
    int v ;
    long long w ;
};
const int MAXN = 400000 ;
long long ans = 0 ;
vector<int>ans1 ; 
vector<Edge>E ;
vector<int> arr(MAXN) ;
int flag = 0 ;

bool BinarySearch(int target){
    bool res = false ;
    int l = 0 ; int r = ans1.size()-1 ;
    while(l <= r){
        int m = (l+r)/2 ;
        if(ans1[m] == target){
            return true ;
        }
        else if(ans1[m] > target){
            r = m - 1 ;
        }
        else{
            l = m + 1 ;
        }
    }
    return res ;
}

int find(int target){
    if(arr[target] < 0){
        return target ;
    }
    return find(arr[target]) ;
}

void Union(int x , int y){
    int x_root = find(x) ;
    int y_root = find(y) ;
    if(abs(arr[x_root]) > abs(arr[y_root])){
        arr[x_root] += arr[y_root] ;
        arr[y_root] = x_root ; 
    }
    else{
        arr[y_root] += arr[x_root] ;
        arr[x_root] = y_root ;
    }
}

void Kruskal(int N , int time){
    int count = 0;
    int pick = 0 ; 
    while(count < N-1 && pick < E.size()){
        if(find(E[pick].u) != find(E[pick].v)){
            if(!time){
                ans += E[pick].w ;
                ans1.push_back(E[pick].id) ;
            }
            else{
                if(BinarySearch(E[pick].id) == false){
                   flag = 1 ;
                   break ; 
                }
            }
            count += 1 ;
            Union(E[pick].u , E[pick].v) ;
        }
        pick += 1 ; 
    }
}

bool cmp1(Edge a , Edge b){
    if(a.w < b.w){
        return true ;
    }
    else if(a.w == b.w &&  a.id < b.id){
        return true ;
    }
    else{
        return false ;
    }
}
bool cmp2(Edge a , Edge b){
    if(a.w < b.w){
        return true ;
    }
    else if(a.w == b.w &&  a.id > b.id){
        return true ;
    }
    else{
        return false ;
    }
}

int main(){
    for(int i = 0 ; i < arr.size() ; i++){
        arr[i] = -1 ;
    }
    int N , M ; 
    cin >> N >> M ;
    while(M--){
        int uu , vv ; long long weight ; 
        cin >> uu >> vv >> weight ; 
        E.push_back({M,uu,vv,weight}) ;
    }

    sort(E.begin() , E.end() , cmp1) ;
    
    Kruskal(N,0) ;
    
    sort(ans1.begin() , ans1.end()) ;
    
    for(int i = 0 ; i < arr.size() ; i++){
        arr[i] = -1 ;
    }
    
    sort(E.begin() , E.end() , cmp2) ;
    
    Kruskal(N,1) ;
    
    cout<<ans;
    cout<<'\n' ;
    if(flag){
        cout<<"NO" ;
        cout<<'\n' ;
    }
    else{
        cout<<"YES" ;
        cout<<'\n' ;
    }
    
    return 0 ;
}
