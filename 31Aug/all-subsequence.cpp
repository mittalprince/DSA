#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void subsequence(char *input, char *output, ll i, ll j){

    if(input[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }

    output[j] = input[i];
    subsequence(input, output, i+1, j+1);
    output[j] = '\0';
    subsequence(input,output,i+1, j);
}
void OwnCode(string str, ll n, string outstr){
    if(n == 0){
        cout<<outstr<<endl;
        return ;
    }
    char ch = str[0];
    string rem = str.substr(1);

    OwnCode(rem, n-1, outstr+'-');
    OwnCode(rem, n-1, outstr+ch);
}


int main(){
    char input[100], output[100];
    cin>>input;
    subsequence(input, output, 0, 0);
    cout<<endl<<endl;
    string In, Out;
    cin>>In;
    OwnCode(In, In.length(), Out);
    cout<<endl;
    return 0;
}