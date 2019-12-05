#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void allSubsequence(char *str, char *output, ll i, ll j){
    if('\0' == str[i]){
        output+= '\0';
        cout<<output<<endl;
        return;
    }

    output[j] = '\0';
    allSubsequence(str, output, i + 1, j);
    output[j] = str[i];
    allSubsequence(str, output, i+1, j+1);
}

int main(){
    char str[100],output[100];
    cin>>str;
    allSubsequence(str, output, 0, 0);
    cout<<endl;
    return 0;
}