#include<iostream>
#include<cstring>
using namespace std;

int countPS(string s){
    int n=s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
    }

    for(int k=2; k<=n; k++){
        for(int i=0; i<n-k+1; i++){
            int j=i+k-1;
            if(s[i] == s[j]){
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
            }
            else{
                dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s;
    cin>>s;
    cout<<countPS(s);
}