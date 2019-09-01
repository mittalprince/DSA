#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void pps(char *a, char *b, ll i, ll j){
    if(a[i] == '\0'){
        b[j] = '\0';
        cout<<b<<endl;
        return 0;
    }

    ll digit = a[i]-'0';
    char ch = digit+'A'-1;
    b[j] = ch;
    pps(a, b, i+1, j+1);

    if(a[i+1] != '\0'){
        ll sd = a[i+1]-'0';
        ll no = 10*digit+sd;
        if(no > 0 && no <= 26){
            b[j] = no+'A'-1;
            pps(a, b,i+1, j+1);
        }
    }
}
int main(){

    char a[100], b[100];
    cin>>a;
    pps(a, b, 0, 0);
    cout<<endl;
    return 0;
}