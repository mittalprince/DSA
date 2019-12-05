#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<(int)(log(n&(n-1))+1)<<endl;
    return 0;
}