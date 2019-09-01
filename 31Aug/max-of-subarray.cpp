#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void MaxSubArr(ll arr[], ll n, ll k){
    ll max = 0;
    for(ll i=0; i<=n-k; i++){
        max = arr[i];
        for(ll j=1; j<k; j++){
            if(max < arr[j+i]){
                max = arr[j+i];
            }
        }
        cout<<max<<" ";
    }
    cout<<endl;
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ll k;
    cin>>k;
    MaxSubArr(arr, n, k);
    return 0;
}