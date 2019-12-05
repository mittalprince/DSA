#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define max 100000

void prime(bool *a){
    for(ll i=2; i<max; i++){
        a[i] = 1;
    }
    for(ll i=2; i<max; i++){
        if(a[i]){
            for(ll j=2*i; j<max; j=j+i){
                a[j] = 0;
            }
        }
    }
}

void printPrime(bool *a, ll n){

    for(ll i=2; i<n; i++){
        if(a[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){
    ll n;
    cin>>n;
    bool arr[max];
    prime(arr);
    printPrime(arr, n);
    return 0;
}