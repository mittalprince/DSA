#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void POS(string str, ll i){

    if(str[i] == '\0'){
        cout<<str<<endl;
        return;
    }

    for(ll j=i; str[j] != '\0'; j++){
        swap(str[i], str[j]);
        POS(str, i+1);
        swap(str[i], str[j]);
    }
}

int main(){

    string str;
    cin>>str;
    POS(str, 0);
    cout<<endl;
    return 0;

}