#include<bits/stdc++.h>
using namespace std;
#define max 10000

int minCoins(int n, int coins[], int dp[], int m){
    if(n == 0){
        return 0;
    }
    if(dp[n]){
        return  dp[n];
    }
    int ans = INT_MAX;
    for(int i=0; i<m; i++){
        if(n-coins[i] >= 0){
            int temp = minCoins(n - coins[i], coins, dp, m) + 1;
            // if(ans != INT_MAX){
                ans = min(temp, ans);
            // }
        }
    }
    return dp[n] = ans;
}

int mC(int n, int coins[], int m){
    int arr[max] = {0};
    
    for(int i=1; i<=n; i++){
        int temp = INT_MAX;
        for(int j=0; j<m; j++){
            if(i-coins[j] >= 0){
                temp = min(temp, arr[i-coins[j]]+1);
            }
        }

        arr[i] = temp;
    }
    return arr[n];
}

int main(){
    int coins[] = {1, 7, 10};
    int m = sizeof(coins)/sizeof(int);
    int n;
    cin>>n;
    int dp[max] = {0};
    cout<<minCoins(n, coins, dp, 3)<<endl;
    cout<<mC(n, coins, 3)<<endl;
}