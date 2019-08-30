#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void swap(ll *x, ll *y){
    ll temp;
    if(*x > *y){
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

void Unique2(ll arr[], ll n, ll *x, ll *y){

    ll Xor = arr[0];
    ll set_bit;
    *x = 0;
    *y = 0;
    for(ll i=1; i<n ;i++){
        Xor = Xor^arr[i];
    }
    set_bit = Xor&~(Xor-1);
    
    for(ll i=0; i<n; i++){
        if(set_bit & arr[i]){
            *x = *x^arr[i];
        }
        else{
            *y = *y^arr[i];
        }
    }
}

int main(){

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll *x = new ll[(sizeof(ll))], *y = new ll[(sizeof(ll))];
    Unique2(arr, n, x, y);
    swap(x, y);
    cout<<*x<<" "<<*y<<endl;
    return 0;
}