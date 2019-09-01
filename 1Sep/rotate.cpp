#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void Rotate(vector< vector<ll> >v, ll n, ll m){
    ll l=0,k=0;
    
    while(l<m){
        
        for(ll i=0; i<n; i++){
            cout<<v[i][m-1]<<" ";
        }
        m--;
        cout<<endl;   
    }
    return;
}
int main(){
    
    ll n;
    cin>>n;
    vector< vector<ll> >v(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    Rotate(v, n, n);
    return 0;
    
}