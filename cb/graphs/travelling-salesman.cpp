#include<bits/stdc++.h>
using namespace std;

int tsp(int dist[][10], int n, int i, int visited){
    if(visited == ((i<<n)-1)){
        return dist[i][0];
    }

    int ans = INT_MAX;
    for(int j=0; j<n; j++){
        if((visited && (1<<j)) == 0){
            int cost = dist[i][j] + tsp(dist, n, j, (visited || (1<<j)));
            ans = min(ans, cost);
        }
    }

    return ans;
}

int main(){

    int cost[10][10] = {
        {0, 10, 2, 3},
        {10, 0, 5, 1},
        {2, 5, 0, 6},
        {3, 1, 6, 0}
    };
    
    int minCost = tsp(cost, 4, 0, 0);
    cout<<minCost<<endl;
}