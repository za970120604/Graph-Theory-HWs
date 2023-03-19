#include<bits/stdc++.h>
#define int long long 
using namespace std;

int edge[19][19];
int n;

bool next_comb(int a[], int len){
    for(int i = len-1; i >= 0; --i){
        if(a[i] < n-len+i+1){
            a[i] += 1;
            for(int j = 1; i+j < len; ++j){
                a[i+j] = a[i]+j;
            }
            return true;
        }
    }
    return false;
}

bool check_K33(){
    int a[] = {1,2,3};
    do{
        int b[] = {1,2,3};
        do{
            if(a[0] == b[0])continue;
            if(a[1] == b[1])continue;
            if(a[2] == b[2])continue;
            int cnt = 0;
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    cnt += edge[a[i]][b[j]];
                }
            }
            if(cnt == 9)return true;
        }while(next_comb(b, 3));
    }while(next_comb(a, 3));
    return false;
}

bool check_K5(){
    if(n < 5)return false;
    int a[] = {1,2,3,4,5};
    do{
        int cnt = 0;
        for(int i = 0; i < 5; ++i){
            for(int j = i+1; j < 5; ++j){
                cnt += edge[a[i]][a[j]];
            }
        }
        if(cnt == 10)return true;
    }while(next_comb(a, 5));
    return false;
}

main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int m,u,v;
    cin >> n >> m;
    memset(edge , 0 , sizeof(edge)) ; 
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    int res1 = check_K33();
    int res2 = check_K5();
    if(res1 && res2){
        cout<<3<<endl;
    }
    else if(res1 && !res2){
        cout<<1<<endl;
    }
    else if(!res1 && res2){
        cout<<2<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
