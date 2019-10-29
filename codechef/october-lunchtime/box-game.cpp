#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin>>t;
	while(t--){
	   ll n,k,ma,mi;
	   int p;
	   cin>>n>>k>>p;
	   ll arr[n];
	   cin>>arr[0];
	   ma = mi = arr[0];
	   for(ll i=1; i<n; i++){
	       cin>>arr[i];
	       if(arr[i] > ma){
	           ma = arr[i];
	       }
	       if(arr[i] < mi){
	           mi = arr[i];
	       }
	   }
	   if(p == 0){
	       if(k&1){
	           cout<<ma<<endl;
	       }
	       else{
	           ll m = max(arr[1], arr[n-2]);
	           for(int i=1; i<n-1; i++){
	               m = max(m, min(arr[i-1], arr[i+1]));
	           }
	           cout<<m<<endl;
	       }
	   }
	   else{
	       if(k&1){
	           cout<<mi<<endl;
	       }
	       else{
	           ll m = min(arr[1], arr[n-2]);
	           for(int i=1; i<n-1; i++){
	               m = min(m, max(arr[i-1], arr[i+1]));
	           }
	           cout<<m<<endl;
	       }
	   }
	}
}