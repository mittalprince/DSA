#include<iostream>
using namespace std;

void Masking(int n, int i, int j){
    int b = (~0);
    b = (b<<(j+1));
    int a = (1<<(i-1))-1;
    int c = a|b;
    int mask = n&c;

    cout<<mask<<endl;
}

int main(){
    int n;
    cin>>n;
    int i,j;
    cin>>i>>j;
    Masking(n,i,j);
    return 0;
}