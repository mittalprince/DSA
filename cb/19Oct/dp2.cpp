#include<bits/stdc++.h>
#include<cmath>
#define max 1000
using namespace std;

int minSteps(int n, int dp[]){
    
    if(n == 1){
        return 0;
    }
    if(dp[n]){
        return dp[n];
    }
    int x,y,z;
    x=y=z= INT_MAX;
    x = minSteps(n-1, dp);
    y = n%2==0? minSteps(n/2, dp): INT_MAX;
    z = n%3==0 ? minSteps(n/3, dp) : INT_MAX;

    int ans = min(x, min(y,z))+1;
    return dp[n] = ans;
}

int BUMinSteps(int n){
    int arr[max] = {0};
    
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i=4; i<=n; i++){
        int x = arr[i-1];
        int y = INT_MAX;
        int z = INT_MAX;
        if(i%2 == 0){
            y = arr[i>>1];
        }

        if(i%3 == 0){
            z = arr[i/3];
        }

        arr[i] = min(x, min(y,z))+1;
    }

    return arr[n];

}
int main(){
    int dp[max] = {0};
    int n;
    cin>>n;
    cout<<minSteps(n, dp)<<endl;
    cout<<BUMinSteps(n)<<endl;

    return 0;
}