#include<bits/stdc++.h>
using namespace std;

int multiply(int a, int b){
    if(b == 0){
        return 0;
    }
    return a+ multiply(a, b-1);
}

int pow(int a, int b){
    if(b == 0){
        return 1;
    }

    int k = pow(a, b/2);
    if(b&1){
        return a*k*k;
    }
    else{
        return k*k;
    }
}
int main(){
    int a, b;
    cin>>a>>b;
    if((a<0 && b<0) || (a>0 && b>0)){
        a = abs(a);
        b = abs(b);
        cout << multiply(a, b) << endl;
    }
    else{
        a = abs(a);
        b = abs(b);
        cout << -1*multiply(a, b) << endl;
    }
    int n=2, m=3;
    cout<<pow(2,3)<<endl;
    return 0;
}