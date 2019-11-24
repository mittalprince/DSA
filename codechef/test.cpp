#include<iostream>
using namespace std;

int main(){
    int c=100;
    int a[3][3] = {{1,2,3,}, {4,5,6}, {7,8,9}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int t = a[i][j]+c;
            a[i][j] = a[j][i];
            a[j][i] = t-c;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    char C = '2';
    cout<<isdigit(C)<<endl;
    cout<<"hello";
}