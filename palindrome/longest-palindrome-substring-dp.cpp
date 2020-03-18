#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int n=s.length();
    if(n<=1) return s;

    /*
    table[i][j] will be false if substring str[i..j] is not palindrome. 
    Else table[i][j] will be true 
    */
    bool table[n][n];
    memset(table, 0, sizeof(table));
    for(int i=0; i<n; i++){
        table[i][i]=true;
    }
    int start=0, maxLength=1;
    // here we check all palindrome sunstring of length 2
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            table[i][i+1]=true;
            start=i;
            maxLength=2;
        }
    }
    //first loop for all possible length of palindorme substr
    for(int k=3; k<=n; k++){
        // second loop for start idx for substr
        for(int i=0; i<n-k+1; i++){
            // j denote the end (idx) of substr
            int j=i+k-1;
            /* 
            checking substr from ith index to jth index iff str[i+1] to str[j-1] is a palindrome
            then we need to check if ith anf jth idx value are same 
            if true table[i][j] will be true and we update the start and maxLength if k>maxLength
            */
            if(table[i+1][j-1] && s[i] == s[j]){
                table[i][j] = true;
                if(k>maxLength){
                    maxLength = k;
                    start=i;
                }
            }
        }
    }
    return s.substr(start, maxLength);
} 
int main(int agrc, char **argv){
    string s;
    cin>>s;
    string ans = longestPalindrome(s);
    cout<<ans<<endl;
}