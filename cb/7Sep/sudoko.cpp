#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canPlace(int grid[9][9], int i, int j, int n ,int number){

    for(int x=0; x<n; x++){
        if(grid[x][j] == number || grid[i][x] == number){
            return false;
        }
    }

    int N = sqrt(n);
    int sx = (i/N)*N;
    int sy = (j/N)*N;

    for(int k=sx; k<sx+N; k++){
        for(int l=sy; l<sy+N; l++){
            if(grid[k][l] == number){
                return false;
            }
        }
    }

    return true;
}

bool sudokoSolver(int grid[9][9], int i, int j, int n){
    if(i==(n-1) && j==(n-1)){
        for(int I=0;I<n; I++){
            for(int J=0; J<n; J++){
                cout<<grid[I][J]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(i>=n || j>=n){
        return false;
    }

    if(grid[i][j] == 0){
        for(int k=1; k<=9; k++){
            if(canPlace(grid, i, j, n, k)){
                grid[i][j] = k;
                bool ans = (sudokoSolver(grid, i + 1, j, n) || sudokoSolver(grid, i, j + 1, n));
                cout<<ans<<endl;
                if(ans){
                    return ans;
                }
                else{
                    grid[i][j] = 0;
                }
            }
        }
        return false;
    }
    return (sudokoSolver(grid, i + 1, j, n) || sudokoSolver(grid, i, j + 1, n));
}

int main(){

    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(sudokoSolver(grid, 0, 0, 9)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    for (int I = 0; I < 9; I++)
    {
        for (int J = 0; J < 9; J++)
        {
            cout << grid[I][J] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}