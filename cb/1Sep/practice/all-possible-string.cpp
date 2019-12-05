#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void APS(char *str, char *Str, ll i, ll j){
    if(str[i] == '\0'){
        Str[j]='\0';
        cout<<Str<<endl;
        return;
    }
    ll digit = str[i]-'0';
    Str[j] = digit+'A'-1;
    APS(str, Str, i+1,j+1);

    if(str[i+1] != '\0'){
        ll temp = str[i+1]-'0';
        ll second = 10*digit+temp;

        if(second<= 26){
            Str[j] = second+'A'-1;
            APS(str, Str, i+2, j+1);
        }
    }
}
int main(){
    char str[100], Str[100];
    cin>>str;
    APS(str, Str, 0, 0);
    cout<<endl;
    return 0;
}