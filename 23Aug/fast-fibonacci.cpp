// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
#include<bits/stdc++.h>

using namespace std;

double FFS(int n){

    double k = (1+sqrt(5))/2;
    return round(pow(k,n)/sqrt(5));
}

int main(){
    int n;
    cin>>n;
    cout<<FFS(n)<<endl;
    return 0;
}
