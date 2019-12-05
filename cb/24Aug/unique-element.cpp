#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n,x;
    cin>>n;
    unordered_map<ll, ll> m;
    for(ll i=0; i<n; i++){
        cin>>x;
        if(m.find(x) != m.end()){
            m[x]++;
        }
        else{
            m[x] = 1;
        }
    }
    set<ll> s;
    for(auto it=m.begin(); it != m.end(); it++){
        if(it->second == 1){
            s.insert(it->first);
        }
    }
    for(auto it=s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    
    cout<<endl;
    return 0;
}