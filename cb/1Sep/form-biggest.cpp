#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(string x, string y){
    
    string xy = x.append(y);
    string yx = y.append(x);
    
    return xy.compare(y) > 0?1:0;
    
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        string str;
        cin>>n;
        vector<string> v;
        for(ll i=0; i<n; i++){
            cin>>str;
            v.push_back(str);
        }
        sort(v.begin(), v.end(), compare);
        for(auto it=v.begin(); it != v.end(); it++){
            cout<<*it;
        }
        cout<<endl;
    }
    return 0;
    
}