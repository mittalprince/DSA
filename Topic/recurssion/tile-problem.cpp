#include<iostream>
using namespace std;

int TW(int n, int m){
   int tw[n+1];
   tw[0] = 0;
    for(int i=1; i<=n; i++){
        if(i>m){
            tw[i] = tw[i-1]+tw[i-m];
        }
        else if(i < m){
            tw[i] = 1;
        }
        else{
            tw[i] = 2;
        }
    }

    return tw[n];
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<TW(n,m)<<endl;
    return 0;
}