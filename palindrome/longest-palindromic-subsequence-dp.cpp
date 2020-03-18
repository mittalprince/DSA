#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int lps(string s){
    int n=s.length();
    
    int table[n][n];
    memset(table, 0, sizeof(table));

    for(int i=0; i<n; i++){
        table[i][i]=1;
    }
    for(int k=2; k<=n; k++){
        for(int i=0; i<n-k+1; i++){
            int j=i+k-1;
            if(s[i] == s[j] && k==2){
                table[i][j] = 2;
            }
            else if(s[i] == s[j]){
                table[i][j] = table[i+1][j-1]+2;
            }
            else{
                table[i][j] = max(table[i][j-1], table[i+1][j]);
            }
        }
    }
    return table[0][n-1];
}

string lcs(string a, string b, int n){
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int len=dp[n-1][n-1];
    int i=n, j=n;
    string ans="";
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else j--;
    }

    return ans;
}
string longestPalSubseq(string s){
    string rev=s;
    int n=s.length();
    reverse(s.begin(), s.end());
    return lcs(s, rev, n);
}

int main(){
    string s;
    cin>>s;
    cout<<lps(s)<<endl;
    cout<<longestPalSubseq(s)<<endl;
}