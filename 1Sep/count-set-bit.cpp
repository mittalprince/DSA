#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++){
        ll no;
        cin>>no;
        ll ct = 0;
        while(no){
            if(no&1){
                ct++;
            }
            no = no>>1;
        }

        cout<<ct<<endl;
    }
    return 0;
}