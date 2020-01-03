#include<iostream>
using namespace std;
#define max 10

bool validPath(char input[max][max], int n, int m, int i, int j){
    if(i>=0 && i<n && j>=0 && j<m && input[i][j] == 'O'){
        return true;
    }
    return false;
}

bool findPath(char input[max][max], char output[max][max], int n, int m, int i, int j){
    if(i==(n-1) && j==(m-1) && input[i][j] =='O'){
        output[i][j] = '1';
        return true;
    }

    if(validPath(input, n, m, i, j) ){
        input[i][j] = '1';
        output[i][j] = '1';

        if(findPath(input, output, n, m, i+1, j)){
            return true;
        }
        if(findPath(input, output, n, m, i-1, j)){
            return true;
        }
        if(findPath(input, output, n, m, i, j+1)){
            return true;
        }
        if(findPath(input, output, n, m, i, j-1)){
            return true;
        }
        output[i][j] = '0';
        input[i][j] = '0';

    }
        return false;
    
} 
int main(){
    int n,m;
    char ch;
    cin>>n>>m;

    char input[max][max], output[max][max];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>input[i][j];
            output[i][j] = '0';
        }
    }
    for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<input[i][j]<<" ";
            }
            cout<<"\n";
        }
    if(findPath(input, output, n, m, 0, 0)){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<output[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"NO PATH FOUND\n";
    }
}