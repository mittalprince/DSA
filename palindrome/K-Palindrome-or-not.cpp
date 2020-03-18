#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lcs(string a, string b, int n, int m){
    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

bool isKPal(string s, int k){
    int n=s.length();
    string rev = s;
    reverse(rev.begin(), rev.end());

    int len = lcs(s, rev, n, n);
    return (n-len <= k);
}

int main(){
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--){
        string s;
        cin >> s;
        int k;
        cin >> k;
        cout << isKPal(s, k) << endl;
    }
    return 0;
}