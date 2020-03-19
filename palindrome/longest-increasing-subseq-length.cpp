#include<iostream>
using namespace std;

int lis(int arr[], int n){
    int dp[n];
    dp[0] = 1;
    int MAX=0;
    for(int i=0; i<n; i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
        MAX = max(MAX, dp[i]);
    }
    return MAX;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<lis(arr, n)<<endl;
    return 0;
}