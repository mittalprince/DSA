/*
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include<iostream>
#include<vector>
using namespace std;

int longestPalindrome(string s){
    int n=s.length();
    vector<int> vec(128, 0);
    for(int i=0; i<n; i++){
        vec[s[i]]++;
    }

    int ct=0, flag=1;
    for(int i=0; i<128; i++){
        if(vec[i]&1){
            ct += vec[i] - 1;
            if(flag==1){
                ct += 1;
            }
            flag=0;
        }
        else if((vec[i]&1)==0){
            ct += vec[i];
        }
    }
    return ct;
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
