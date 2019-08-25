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
            break;
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
    
    if( s <= e){

        ll mid = (s+e)/2;

        if(arr[mid] == key){
            return mid;
        }

        if(arr[mid] > key){
            return RBS(arr, s, mid-1, key);
        }
        return RBS(arr, mid+1, e, key);
    }
    return -1;
}

int main(){ 
    ll n = 5;
    ll arr[] = {2,3,3,10,40}; 
    ll ans = BS(arr,n,3);
    if(ans == -1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<ans<<endl;
    }

    ll result = RBS(arr, 0, n-1, 3);
    (result == -1) ?cout<<"Element not present"<<endl : cout<<"Element is at index "<<result<<endl;
    return 0;
}