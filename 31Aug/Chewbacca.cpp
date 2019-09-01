#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    char number[20];
    cin>>number;
    ll i=0;
    if(number[i] == '9'){
        i++;
    }

    while(number[i] != '\0'){
        ll digit = number[i] - '0';
        if(digit > 4){
            digit = 9 - digit;
            number[i] = digit + '0';
        }
    }

    cout<<number<<endl;
    return 0;

}