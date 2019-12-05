#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll NaiveApproach(ll arr[], ll n){
    ll curr_sum = 0;
    ll max_sum = INT_MIN;

    for(ll i=0; i<n; i++){
        for(ll j=i; j<n; j++){
            curr_sum = 0;
            for(ll k=i; k<=j; k++){
                curr_sum += arr[k];
            }
            if(max_sum < curr_sum){
                max_sum = curr_sum;
            }
        }
    }

    return max_sum;
}

ll Cumulative_Sum_Approach(ll arr[], ll n, ll CS[])
{
    ll max_sum = INT_MIN;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i; j < n; j++)
        {
            if(max_sum < (CS[j] - CS[i-1])){
                max_sum = CS[j] - CS[i - 1];
            }
        }
    }

    return max_sum;
}

ll KadneAlgo(ll arr[], ll n){
    ll max_so_far = 0;
    ll max_ending_here = 0;

    for(ll i=0; i<n; i++){
        max_ending_here += arr[i];
        if(max_ending_here < 0){
            max_ending_here = 0;
        }
        if(max_so_far<max_ending_here){
            max_so_far = max_ending_here;
        }
    }

    return max_so_far;
}

int main(){

    ll n;
    cin>>n;
    ll arr[n];
    ll c_sum[n];
    cin>>arr[0];
    c_sum[0] = arr[0];
    for(ll i=1; i<n; i++){
        cin>>arr[i];
        c_sum[i] = c_sum[i-1]+arr[i];
    }
    cout<<NaiveApproach(arr, n)<<endl;
    cout<<Cumulative_Sum_Approach(arr, n, c_sum)<<endl;
    cout<<KadneAlgo(arr, n)<<endl;
    return 0;

}