#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll first=0, second=1, temp = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<=i; j++){
            cout<<first<<"\t";
            temp = first + second;
            first = second;
            second = temp;
        }
        cout<<endl;
    }
    return 0;
}