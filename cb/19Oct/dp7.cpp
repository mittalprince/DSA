#include<bits/stdc++.h>
using namespace std;
#define max 100000

int lis(int arr[], int n){
    int dp[max] = {0};

    dp[0] = 1;

    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }

    int m = 0;
    for(int i=0; i<n; i++){
        if(m < dp[i]){
            m = dp[i];
        }
    }

    return m;
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<lis(arr, n)<<endl;

}