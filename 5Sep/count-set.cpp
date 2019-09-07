#include<iostream>
using namespace std;
typedef long long ll;

ll CountSetbit(ll n){
    ll ans = 0;
    while(n){
        if(n & 1){
            ans++;
        }

        n = n>>1;
    }

    return ans;
}

ll BetterApp(ll n){

    ll count = 0;
    while(n){
        n = n&(n-1);
        count++;
    }
    return count;
}
int main(){
    ll n;
    cin>>n;
    cout<<CountSetbit(n)<<endl;
    cout<<BetterApp(n)<<endl;
    return 0;
}