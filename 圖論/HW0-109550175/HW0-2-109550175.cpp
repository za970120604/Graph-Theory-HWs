#include <iostream>
using namespace std;

int main(){
    int n ; 
    cin >> n;
    int a[n+1] ; 
    for(int i = 0 ; i < n+1 ; i++){
        a[i] = 0 ; 
    }
    for(int i = 0 ; i < n ; i++){
        int c ; 
        cin >> c ;
        a[c]++ ; 
    } 
    int time = 0 ; 
    for(int i = 0 ; i < n+1 ; i++){
        if(a[i] > time){
            time = a[i] ;  
        }
    }
    for(int i = 0 ; i < n+1 ; i++){
        if(a[i] == time){
            cout<<i<<" "<<time<<endl;
        }
    }
   
    return 0 ; 
}
