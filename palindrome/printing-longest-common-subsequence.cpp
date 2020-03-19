#include<iostream>
#include<set>
using namespace std;
#define MAX 100

int dp[MAX][MAX];

set<string> findLCS(string a, string b, int n, int m){
    set<string>s;

    if(m==0 || n==0){
        s.insert("");
        return s;
    }
    if(a[n-1] == b[m-1]){
        set<string> temp=findLCS(a, b, n-1, m-1);
        for(auto i: temp){
            s.insert(i+a[n-1]);
        }
    }
    else{
        if(dp[n-1][m]>=dp[n][m-1]){
            s = findLCS(a, b, n-1, m);
        }
        if (dp[n - 1][m] <= dp[n][m - 1]){
            set<string> temp=findLCS(a,b,n, m-1);
            for(auto &i: temp){
                s.insert(i);
            }
        }
    }
    return s;
}

void lcs(string a, string b, int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main(){
    string a,b;
    cin>>a>>b;
    lcs(a,b,a.length(),b.length());
    set<string> s=findLCS(a,b,a.length(),b.length());
    for(string i: s){
        cout<<i<<endl;
    }
}