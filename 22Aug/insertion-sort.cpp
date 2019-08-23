#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void IS(ll arr[], ll n){
    ll i,j,key;

    for(i=1; i<n; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(ll arr[], ll n){
    for(ll i=0; i<n; i++){
        cout<<arr[i]<<" ";
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
    IS(arr, n);
    printArray(arr, n);
    return 0;
}