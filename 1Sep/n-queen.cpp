#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSafe(int board[][10], int n, int i, int j){

    for(int k=0; k<i; k++){
        if(board[k][j]){
            return false;
        }
    }

    int x=i, y=j;
    while(x>=0 && y>=0){
        if(board[x][y]){
            return false;
        }
        x--;
        y--;
    }

    x=i, y=j;
    while(x>=0 && y<n){
        if(board[x][y]){
            return false;
        }
        x--;
        y++;
    }

    return true;
}


int nqueen(int board[][10], int n, int i){

    if(i == n){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout<<board[j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return 1;
    }

    int ans = 0;
    for(int j=0; j<n; j++){
        if(isSafe(board, n, i, j)){
            board[i][j] = 1;
            int remainingways = nqueen(board, n ,i+1);
            ans += remainingways;
            board[i][j] = 0;
        }
    }

    return ans;
}

int main(){
    int n;
    int board[10][10] = {0};
    cin>>n;
    cout<<nqueen(board, n, 0)<<endl;
    return 0;
}