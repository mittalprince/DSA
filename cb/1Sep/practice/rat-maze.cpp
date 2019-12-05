#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gridways(char board[][10], int m, int n, int i, int j){

    if(i==(m-1) && j==(n-1)){
        board[i][j] = '1';
        for(int p=0; p<m; p++){
            for(int q=0; q<n; q++){
                cout<<board[p][q]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        board[i][j] = '0';
        return 1;
    }

    if(i>=m || j>=n){
        return 0;
    }

    if(board[i][j] == 'X'){
        return 0;
    }
    board[i][j] = '1';
    int x = gridways(board, m, n, i+1, j);
    int y = gridways(board, m, n, i, j+1);
    board[i][j] = '0';
    return x+y;
}
int main(){
    int m, n;
    char board[10][10] = {
        "0000X",
        "00X00",
        "000XX",
        "XX000",
    };

    cout <<gridways(board, 4, 5, 0, 0) << endl;
    return 0;
}