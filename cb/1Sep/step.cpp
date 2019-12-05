#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ct = 0;
void TotalWays(ll n, ll k, string str){

    if(n == 0){
        ct++;
        cout<<str<<endl;
        return;
    }

    for(ll i=1; i<=k; i++){
        if(i<=n){
            str += to_string(i);
            TotalWays(n-i, k, str);
            str[str.length()-1] = '\0';
        }
    }
}

ll ways(ll n, ll k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    ll ans = 0;
    for(ll i=1; i<=k; i++){
        ans += ways(n-i, k);
    }
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    string str;;
    TotalWays(n,k, str);
    cout<<ct<<endl;
    return 0;
}