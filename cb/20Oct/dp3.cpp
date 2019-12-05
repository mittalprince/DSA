#include<bits/stdc++.h>
using namespace std;
#define Max 1000

int knapsack(int wt[], int val[], int W, int n){
    
    int knap[Max][Max] = {0};

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            
            if(i==0 || j==0){
                knap[i][j] = 0;
            }

            else if(wt[i-1] <= j){
                knap[i][j] = max(knap[i-1][j], val[i-1]+knap[i-1][j-wt[i-1]]);
            }
            else{
                knap[i][j] = knap[i-1][j];
            }
        }
    }

    return knap[n][W];
}
int main(){

    int wt[] = {5,2,1,3};
    int val[] = {100, 70, 50, 80};
    int n=4;
    int W = 8;

    cout<<knapsack(wt, val, W, n)<<endl;
}


// bc ajj yeh ghar par yeh karna hai