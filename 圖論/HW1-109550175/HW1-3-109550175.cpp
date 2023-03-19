#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>vec ;
vector<long long>D;
bool cmp(int a , int b){
    return a > b ; 
}
int BinarySearch(int target , int start){
    int l = start ; int r = vec.size()-1;
    int res = -1 ; 
    while(l<=r){
        int m = (l+r)/2 ;
        if(vec[m] == target){
            res = m ; 
            l = m + 1 ; //find last occurence
        }
        else if(vec[m] < target){
            r = m - 1 ;
        }
        else{
            l = m + 1 ;
        }
    }
    if(res == -1){
        return r ; 
    }
    else{
        return res ; 
    }
}
int main(){
    cin.tie(0) ;
    cin.sync_with_stdio(0) ;
    int n ; 
    cin >> n ;
    long long sum = 0 ; 
    vec.push_back(n+1) ;
    D.push_back(n+1) ;
    int N = n ; 
    while(n--){
        int a ; 
        cin >> a ; 
        vec.push_back(a) ;
        sum += a ; 
    }
    sort(vec.begin() , vec.end() , cmp) ;
    for(int i = 1 ; i < vec.size() ; i++){
        if(D.size() == 1){
            D.push_back(vec[i]);
        }
        else{
            D.push_back(D[i-1] + vec[i]);
        }
    }
    
    if(sum %2 != 0){
        cout<<"No";
        cout<<'\n';
    }
    else{
        int flag = 1 ; 
        for(long long k = 1 ; k <= N ; k++){
            if(k*(k-1) >= D[k]){
                continue ;
            }
            else{
                long long part = 0 ;
                if(k < N){
                    int end_multiply_k = BinarySearch(k,k+1); //find last element >= k ;
                    if(end_multiply_k < k+1){
                        part += D[N]-D[k] ;
                    }
                    else{
                        part += k*(end_multiply_k-k) ;
                        if(end_multiply_k + 1 == N){
                            part += vec[N] ;
                        }
                        else if(end_multiply_k + 1 < N){
                            part += D[N] - D[end_multiply_k] ;
                        }
                    }  
                }
                if(D[k] > (part + k*(k-1))){
                    flag = 0 ; 
                    break ; 
                }
            } 
        }
        if(!flag){
            cout<<"No";
            cout<<'\n';
        }
        else{
            cout<<"Yes" ;
            cout<<'\n' ;
        }
    }
    return 0 ; 
}
