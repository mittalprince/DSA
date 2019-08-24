#include<iostream>
using namespace std;
typedef long long ll;

ll BS(ll arr[], ll n, ll no){
    ll s = 0;
    ll e = n-1;
    ll ans = -1;
    ll mid = (s+e)/2;
    while(s<=e){
        if(no == arr[mid]){
            ans = mid;
            // e = mid-1; for first occurence
            // s = mid+1 for last occurence
        }
        else if(no < arr[mid]){
            e=mid-1;
        }
        else{
            s= mid+1;
        }
        mid = (s+e)/2;
    }
    return ans;
}

ll RBS(ll arr[], ll s, ll e, ll key){
    if(s<=e){}
}

int main(){ 
    ll n = 9;
    ll arr[] = {2,3,3,3,4,6,6,6,9};
    ll ans = BS(arr,n,3);
    if(ans == -1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<ans+1<<endl;
    }
    return 0;
}