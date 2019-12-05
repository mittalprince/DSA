#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void swap(ll *x, ll *y){
    ll tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(ll arr[], ll n, ll i){

    if(n == i || (n == 1)){
        return;
    }

    if(arr[i]>arr[i+1]){
        swap(arr[i], arr[i+1]);
    }
    sort(arr, n, i+1);
    sort(arr, n-1, i);
}

void bubbleSort(ll arr[], ll n){
    if(n == 1){
        return;
    }
    sort(arr, n, 0);
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
