#include<bits/stdc++.h>
using namespace std;
#define max 100000
int possibleCombination(int n, int dp[]){
    if(n == 0 || n == 1 || n == 2) {
        return n;
    }

    if(dp[n]){
        return dp[n];
    }

    return dp[n] = possibleCombination(n-1, dp) +(n-1)*possibleCombination(n-2, dp);

}
int main(){
    int n;
    cin>>n;
    int dp[max] = {0};
    cout<<possibleCombination(n, dp)<<endl;
}