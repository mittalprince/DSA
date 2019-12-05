#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char Phone[][10]= {
        ",@",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
        "+",
        "#"
    };

void PhoneCombination(char *str, char *Str, ll i, ll j){
    if( str[i] == '\0'){
        Str[j] = '\0';
        cout<<Str<<endl;
        return;
    }
    ll digit = str[i]-'0';
    for(ll J=0; Phone[digit][J] != '\0'; J++){
        Str[j] = Phone[digit][J];    
        PhoneCombination(str, Str, i+1, j+1);
    }

}

int main(){

    char str[100], Str[100];
    cin>>str;
    PhoneCombination(str, Str, 0, 0);
    cout<<endl;
    return 0;
}