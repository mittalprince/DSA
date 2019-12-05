#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int tw(int n, int i, int j){

    if(i==n || j==n){
        return 1;
    }

    if(dp[i][j]){
        return dp[i][j];
    }

    int ans = 0;
    for(int k=i; k<n; k++){
        ans += tw(n, i + k, j);
        // ans += tw(n, i, j + k);
    }
    for(int k=j; k<n; k++){
        // ans += tw(n, i + k, j);
        ans += tw(n, i, j + k);
    }

    return dp[i][j] = ans;
}


int BU(int n){
    int arr[1000][1000];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp = 0;
            for(int k=0; k<i; k++){
                temp += arr[i][j];
            }
            for(int k=0; k<j; k++){
            
            }
        }
    }
}
int main(){
    int n;
    cin>>n;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dp[i][j] = 0;
        }
    }

    cout<<tw(n, 0, 0)<<endl;
}