#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void toh(ll n, char s_r, char d_r, char a_r){
    if(n == 1){
        cout<<"Move disk 1 fromn "<<s_r<<" to "<<d_r<<endl;
        return;
    }
    toh(n-1, s_r, a_r, d_r);
    cout<<"Move disk "<<n<<" from "<<s_r<<" to "<<d_r<<endl;
    toh(n-1, a_r, d_r, s_r);
}

ll fastPow(ll a, ll b){
    if(b == 0){
        return 1;
    }

    ll k = fastPow(a, b/2);
    if(b%2 != 0){
        return a*k*k;
    }
    else{
        return k*k;
    }
}

ll totalMoves(ll n){
    ll k = fastPow(2,n)-1;
    return k;
}

int main() {
    ll n;
    cin>>n;
    cout<<"Total Moves "<<totalMoves(n)<<endl;
    toh(n, 'A', 'C', 'B');
    return 0;
}