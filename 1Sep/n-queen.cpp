#include<bits/ctsdc++.h>
using namespace st;
typedef long long ll;

#define max 4

bool isSave(ll arr[max][max], i, j, n){

}

ll NQUeen(ll arr[max][max], ll i, ll n){
    if(n == i){
        // print board
        return 1;
    }
    // try all col in the curr row;
    for(ll j=0; j<n; i++){
        if(isSave(arr, i, j, n)){
            borard[i][j] = 1;
        }
    }

}
int main(){
    ll n;
    arr[max][max];


}