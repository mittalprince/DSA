#include<iostream>

using namespace std;
typedef long long ll;
#define mod 1000000007

ll TotalWays(ll n, ll m){
    if(n == 0){
        return 0; 
    }
    if(n < m){
        return 1;
    }

    if(n == m){
        return 2;
    }

    return TotalWays(n-1, m) + TotalWays(n-m, m);
}

int main(){

    ll n,m;
    cin>>n>>m;
    cout<<(TotalWays(n, m)%mod)<<endl;
    return 0;
}