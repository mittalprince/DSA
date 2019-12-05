#include<bits/stdc++.h>
using namespace std;
#define max 100000

int possibleBST(int n, int dp[]){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    if(dp[n]){
        return dp[n];
    }
    int ans = 0;
    for(int i=1; i<= n; i++){
        ans += possibleBST(i-1, dp) * possibleBST(n-i, dp);
    }

    return dp[n] = ans;
}

// int pBST(int n){
//     int arr[max] = {0};
//     arr[0] = 1;

//     for(int i=1; i<=n; i++){
//         int temp = 1;
//         if(i-1 > 0){
//             temp = arr[i-1];
//         }
//         if(n-i > 0){
            
//         }
//     }
//     return 0;
// }

int main(){
    int n;
    int dp[max] = {0};
    cin>>n;
    cout<<possibleBST(n, dp)<<endl;
}