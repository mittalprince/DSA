#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll arr[n];

    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll unique = 0;
    for(ll i=0; i<n; i++){
        unique = unique^arr[i];
    }

    cout<<unique<<endl;
    return 0;
}