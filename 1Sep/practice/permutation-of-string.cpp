#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void POS(string str, ll i){
    if(str[i] == '\0'){
        cout<<str<<endl;
        return;
    }

    for(ll j=i; j<str.length(); j++){
        swap(str[j], str[i]);
        POS(str, i+1);
        swap(str[j], str[i]);
    }
}
int main(){
    string str;
    cin>>str;
    POS(str, 0);
    cout<<endl;
    return 0;
}