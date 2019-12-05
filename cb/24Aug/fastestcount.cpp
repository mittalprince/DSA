#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> v(n);
		cin>>a>>b;
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}

		sort(v.begin(), v.end());

		for(ll i=0; i<n; i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}      
