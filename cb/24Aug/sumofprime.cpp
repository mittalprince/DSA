#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define max 100000
ll prefix[max+1];

void buildPrefix(){
    bool arr[max+1];
    for(ll i=0; i<=max; i++){
        arr[i] = 1;
    }

    for(ll i=2; i<=max; i++){
        if(arr[i]){
            for(ll j=2*i; j<=max; j += i){
                arr[j] = 0;
            }
        }
    }

    prefix[0] = prefix[1] = 0;
    for(ll i=2; i<=max; i++){
        prefix[i] = prefix[i-1];
        if(arr[i]){
            prefix[i] += i;
        }
    }
}

ll suminRange(ll l, ll r){
    buildPrefix();

    return prefix[r] - prefix[l-1];
}

int main(){
    ll l,r;
    cin>>l>>r;

    cout<<suminRange(l,r)<<endl;
    return 0;
}