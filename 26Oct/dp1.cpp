#include<bits/stdc++.h>
using namespace std;
#define max 10000

int dp[100][100];

int wines(int n ,int arr[], int i, int j, int y){
    if(i > j){
        return 0;
    }

    if(dp[i][j]){
        return dp[i][j];
    }
    int op1 = arr[i]*y + wines(n, arr, i+1, j, y+1);
    int op2 = arr[j]*y + wines(n, arr, i, j-1, y+1);


    return dp[i][j] = op1 > op2 ? op1 : op2;
}

int BU(int n, int arr[]){
    int dp[1000][1000];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = 0;
        }
    }

}
int main(){

    int n = 5;
    int arr[5] = {2,3,5,1,4};

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dp[i][j] = 0;
        }
    }

    cout<<wines(n, arr, 0, n-1, 1)<<endl;

}