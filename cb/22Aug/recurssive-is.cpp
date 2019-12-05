#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll RI(ll arr[], ll index, ll key){
    cout<<"Incoming "<<index<<endl;
    if(index == 0 || arr[index] < key){
        return index-1;
    }

    return RI(arr, index-1, key);
}
void RIS(ll arr[], ll n){
    if(n == 0 || n == 1){
        return;
    }

    RIS(arr, n-1);

    ll key = arr[n-1];
    ll j = n-2;

    while(j>=0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = key;
    // j = RI(arr, j, key);
    // cout<<" j "<<j<<endl;
    // arr[j+1] = key; 
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
    RIS(arr, n);
    printArray(arr, n);
    return 0;
}