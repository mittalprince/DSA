// https://www.geeksforgeeks.org/print-a-pattern-without-using-any-loop/

#include<iostream>

using namespace std;
typedef long long ll;

void PP(ll n){
    if(n == 0 || n < 0){
        cout<<n<<" ";
        return;
    }

    cout<<n<<" ";
    PP(n-5);
    cout<<n<<" ";
}

int main(){

    ll n;
    cin>>n;
    PP(n);
    cout<<endl;
    return 0;
}