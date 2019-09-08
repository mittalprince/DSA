#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    char ch[20];
    cin>>ch;
    ll len = strlen(ch);
    ll ans = 0;
    ans = (1<<len)-2;
    for(ll i=len-1, pos=0; i>=0; i--, pos++){
        if(ch[i] == '7'){
            ans += (1<<pos);
        }
    }
    cout<<ans+1<<endl;
    return 0;
}