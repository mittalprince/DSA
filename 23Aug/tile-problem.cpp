#include<iostream>

using namespace std;
typedef long long ll;

ll TotalWays(ll n, ll m){
    if(n == 0){
        return 0; 
    
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
    cin>>m>>n;
    cout<<TotalWays(n, m)<<endl;
    return 0;
}