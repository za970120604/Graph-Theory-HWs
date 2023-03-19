#include <iostream>
using namespace std;
int main(){
    int n ; int a  ; int b ; int c ; 
    cin >> n >> a >> b >> c ;
    int A[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int a ; 
            cin >> a ; 
            A[i][j] = a ;
        }
    }

    int point[n] ; 
    for(int i = 0 ; i < n ; i++){
        point[i] = 0 ;
    }
    
    for(int i = 0 ; i < n ; i++){
        int pts = 0 ; 
        for(int j = 0 ; j < n ; j++){
            if(i == j){
                continue ; 
            }
            else{
                if(A[i][j] == 0){
                    pts+=b ;
                }
                else if(A[i][j] == 1){
                    pts+=a;
                }
                else if(A[i][j] == 2){
                    pts+=c;
                } 
            }
        }
        point[i]+=pts ;
    }
    for(int  i = 0 ; i < n ; i++ ){
        cout<<point[i]<<" ";
    }
    return 0 ; 
}
