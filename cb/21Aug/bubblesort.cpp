#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void swap(ll *x, ll *y){
    ll tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(ll arr[], ll n){
    if(n == 0){
        cout<<"Array Empty"<<endl;
    }

    else{
        ll i,j;
        for(i=0; i<n-1; i++){
            for(j=0; j<n-i-1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
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
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}