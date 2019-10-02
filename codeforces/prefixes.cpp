#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll n;
    cin >> n;

    string s;
    cin>>s;
    ll a = 0;
    ll b = 0;
    ll j=0;
    ll ct = 0;
    while (s[j+1] != '\0')
    {
        if(s[j] == s[j+1]){
            ct++;
        }
        j = j+2;
    }

    a = a / 2;
    b = b / 2;
    cout <<ct << endl;

    for (ll i = 0; i < n; i += 2)
    {
        if(s[i] != s[i+1]){
            cout<<s[i]<<s[i+1];
        }
        else{
            if(s[i] == 'a'){
                cout<<"ab";
            }
            else{
                cout<<"ba";
            }
        }
    }
    cout<<endl;
}