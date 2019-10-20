#include<bits/stdc++.h>
using namespace std;
#define max 100000

int rC(int n, int k, int dp[]){

    if(n == 0){
        return 1;
    }
    if(dp[n]){
        return dp[n];
    }

    int ans = 0;
    for(int j=1; j<=k; j++){
        ans +=  (n-j>=0 ? rC(n-j, k, dp): 0);
    }

    return dp[n] = ans;
}
int minStpesLadder(int n, int k){
    int arr[max] = {0};
    arr[0] = 1;
    arr[1] = 1;
    int sum = 0;

    for(int j=2; j<=n; j++){
        if(j-k > 0){
            arr[j] += 2*arr[j-1] - arr[j-k];
        }
        else{
            arr[j] += 2*arr[j-1];
        }
    }


    return arr[n];
}

int main(){
    int dp[max] = {0};
    int n,k;
    cin>>n>>k;
    cout<<rC(n,k,dp)<<endl;
    cout<<minStpesLadder(n,k)<<endl;
}