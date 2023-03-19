#include <iostream>
#include <memory.h>
#include <map>
struct item{
    int reverse ;
    int value ;
    int reverse_value ; 
};
using namespace std;
int main(){
    int n,k,a,b,c;
    cin >> n >> k >> a >> b >> c ;
    int M[n][n] ;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++){
            int a ; cin >> a ; 
            M[i][j] = a ;
        }
    }
    int mmax = -1 ;
    int mmin = a*n + 1;
    int value[n] ; 
    for(int i = 0 ; i < n ; i++){
        int pts = 0 ; 
        for(int j = 0 ; j < n ; j++){
            if(i != j ){
                if(M[i][j] == 0){
                    pts += b ; 
                }
                else if(M[i][j] == 1){
                    pts += a ; 
                }
                else{
                    pts += c ;
                }
            }
        }
        value[i] = pts ;
        if(pts > mmax){
            mmax = pts ; 
        }
        if(pts < mmin){
            mmin = pts ;
        }
    }
    while(k--){
        int i,j,res ; 
        cin >> i >> j >> res ;
        map<int,item>mp ; mp[0] = {1,b,a} ;mp[1] = {0,a,b} ;mp[2] = {2,c,c} ;
        if(M[i-1][j-1] != res){
            value[i-1] += mp[res].value - mp[M[i-1][j-1]].value ;
            M[i-1][j-1] = res ;
//            cout<<M[i-1][j-1]<<" "<<value[i-1]<<endl; 
        }
        if(M[j-1][i-1] != mp[res].reverse){
            value[j-1] += mp[res].reverse_value - mp[M[j-1][i-1]].value ; 
            M[j-1][i-1] = mp[res].reverse ;
//            cout<<M[j-1][i-1]<<" "<<value[j-1]<<endl; 
        }
        mmax = 0 ; 
        mmin = a*n +1;
        for(int i = 0 ; i < n ; i++){
            mmax = max(mmax , value[i]);
            mmin = min(mmin , value[i]);
        }
        cout<<mmax-mmin<<" ";
    }
    return 0 ; 
}
