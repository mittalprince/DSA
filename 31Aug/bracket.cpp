#include<bits/stdc++.h>
using namespace std;

void BB(string s, int i, int j, int n){
   
   if(j == n && i == n){
       s += '\0';
       cout<<s<<endl;
       return;
   }
   
   if(i>j){
       BB(s+')', i, j+1, n);
   }
   if(i<n){
       BB(s+'(', i+1, j, n);
   }
}

int main(){
    int n;
    cin>>n;
    string s;
    BB(s, 0, 0, n);
    return 0;
}