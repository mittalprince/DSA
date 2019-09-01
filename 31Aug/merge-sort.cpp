#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(ll arr[], ll s, ll e, ll n){
    ll mid = (s+e)/2;
    ll i=s, k=s,j=mid+1;
    ll temp[n];
    while(i<=mid && j<=e){

        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }

        if (arr[i] > arr[j])
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j<=e){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(ll i=s; i<=e; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(ll arr[], ll s, ll e, ll n){

    if(s >= e){
        return;
    }
    ll mid = (s+e)/2;

    mergeSort(arr, s, mid, n);
    mergeSort(arr, mid+1, e, n);

    return merge(arr, s, e, n);
    // return;
}
int main(){

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1, n);
    for(ll i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
     return 0;
}