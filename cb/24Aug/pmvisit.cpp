#include<iostream>

using namespace std;
typedef long long ll;
#define max 1000000
ll prefix[max+1];

void SOA(){
    bool prime[max+1];
    for(ll i=0; i<=max; i++){
        prime[i] = 1;
    }   

    for(ll i=2; i*i<= max; i++){
        if(prime[i]){
            for(ll j=2*i; j<=max; j+= i){
                prime[j] = 0;
            }
        }
    }

    prefix[0] = prefix[1] = 0;
    for(ll i=2; i<=max; i++){
        prefix[i] = prefix[i-1];
        if(prime[i]){
            prefix[i]++;
        }
    }
}

ll NoC(ll l, ll r){
    return prefix[r] - prefix[l-1];
}

int main(){
    ll t,r,l;
    cin>>t;
    SOA();
    while(t--){
        cin>>l>>r;
        cout<<NoC(l,r)<<endl;
    }
    return 0;
}
