#include<iostream>
#include<unordered_map>
using namespace std;

typedef long long ll;
#define M 1000000007
unordered_map<ll, ll> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d,m,n;
        cin>>a>>b>>c>>d>>m>>n;
        ll arr[n];
        for(ll i=0; i<n; i++){
            cin>>arr[i];
            mp[(((arr[i]*arr[i])%m)+m)%m]++;
        }   
        ll ans = 0;
        for(ll i=0; i<n; i++){
            ll x = (((((((a * arr[i]) % m) * ((arr[i] * arr[i]) % m)) % m) + (b * ((arr[i] * arr[i]) % m) % m) + ((c * arr[i]) % m) + d) % m) + m) % m;
            if(mp.find(x) != mp.end()){
                ans += mp[x];
            }
        }
        cout<<(ans%M)<<endl;
        mp.clear();
    }
}

//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/lets-plot-this-47a575ed/