#include<iostream>
#include<cstring>
using namespace std;

int CountPS(string s){
    int n=s.length();
    int dp[n][n];
    bool pal[n][n];
    memset(dp, 0, sizeof(dp));
    memset(pal, false, sizeof(pal));

    for(int i=0; i<n; i++){
        // dp[i][i]=1;
        pal[i][i]=true;
    }
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            pal[i][i+1]=true;
            dp[i][i+1]=1;
        }
    }
    for(int k=2; k<n; k++){
        for(int i=0; i<n-k; i++){
            int j=i+k;
            if(s[i] == s[j] && pal[i+1][j-1]){
                pal[i][j]=true;
            }
            dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            if(pal[i][j]) = dp[i][j]++;
        }
    }
    return dp[0][n-1];
} 
int main()
{
    string s;
    cin>>s;
    cout<<CountPS(s)<<endl;
    return 0;
}