#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans = -1;

void RSearch(ll arr[], ll s, ll e){
    if(s > e){
        return;
    }

    ll mid = (s+e)/2;
    if(arr[mid] > arr[mid+1]){
        ans = mid;
    }
    RSearch(arr, mid+1, e);
    RSearch(arr, s, mid-1);
} 

int main(){
    ll arr[] = {1,2,3,3,2,1};
    ll n = sizeof(arr)/sizeof(arr[0]);
    // ll index = -1;
    // for(ll i=0 ;i<n-2; i++){
    //     if(arr[i] < arr[i+1]){
    //         index = i;
    //         break;
    //     }
    // }

    // cout<<index-1<<endl;
    RSearch(arr, 0, n);
    cout<<ans<<endl;
    return 0;
}
