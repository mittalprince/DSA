#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isPrime(ll n){
    for(ll j=2; j<= sqrt(n); j++){
        if(n%j == 0){
            return false;
        }
    }
    return true;

}

void primrNo(ll n){
    // ll i,j;
    // for(i=2; i<=n; i++){
    //     for(j=2; j<= sqrt(i); j++){
    //         if(i%j == 0){
    //             break;
    //         }
    //     }

    //     if(j > sqrt(i)){
    //         cout<<i<<" ";
    //     }
    // }
    if(n<2){
        return;
    }

    if(n == 2){
        cout<<"2 ";
        return ;
    }
    else{
        cout<<"2 ";
        for(ll i=3; i<=n ; i=i+2){
            if(isPrime(i)){
                cout<<i<<" ";
            }
        }
    }
    
}

int main(){
    
    ll n;
    cin>>n;
    primrNo(n);
    cout<<endl;
    return 0;
}