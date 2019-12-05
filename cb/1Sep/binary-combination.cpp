#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll TC(ll n){

    if(n == 1){
        return 2;
    }  
    if(n == 2){
        return 3;
    }

    return TC(n-1)+TC(n-2);

}

int main(){
    ll n;
    cin>>n;
    return 0;
}