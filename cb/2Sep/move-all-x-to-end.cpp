#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void RX(char *str, ll i, ll length){
    if(i == length || i>length){
        cout<<str<<endl;
        return;
    }
    
    if(str[i] == 'x'){
        
        for(ll j=i; j<length; j++){
            str[j] = str[j+1];
        }
        str[length] = 'x';
        RX(str, i+1, length-1);
    }
    else{
        RX(str, i+1, length);
    }
}
int main(){
    char a[1000];
    cin>>a;
    ll i=0; 
    while(a[i] != '\0'){
        i++;
    }
    // cout<<i;
    RX(a, 0, i-1);
    return 0;
}