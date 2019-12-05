#include<bits/stdc++.h>
using namespace std;

int main(){

    char ch[1000];
    cin>>ch;
    int j=0; 
    stack<char> s;
    while(ch[j]!= '\0'){
        s.push(ch[j]);
        j++;
    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}