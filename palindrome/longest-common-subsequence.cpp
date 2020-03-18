#include<iostream>
using namespace std;

void lcs(string a, string b, int n, int m){
    int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
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

    string ans="";

    int i=n, j=m;
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

    cout<<ans<<endl;
}
int main(){
    string a,b;
    cin>>a>>b;
    lcs(a,b,a.length(),b.length());
    return 0;
}