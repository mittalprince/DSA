#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll TW(ll n, ll k){
    if(n == 0 || n == 1 || n == 2){
        return n;
    }

    return TW(n-1, k)+ ((n-1)*TW(n-2, k));

}
int main(){
    ll n,k;
    cin>>n>>k;
    cout<<TW(n,k)<<endl;
    return 0;
}