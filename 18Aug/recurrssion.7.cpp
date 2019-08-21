#include<bits/stdc++.h>

using namespace std;

int multiply(int a, int b){
    if(b == 0){
        return 0;
    }

    return a + multiply(a, b-1);
}

int power(int a, int b){
    
    if(b == 0){
        return 1;
    }
    
    // return multiply(a, power(a, b-1));
    return a*power(a,b-1);
}

int fastPow(int a, int b){
    
    if(b == 0){
        return 1;
    }
    int k = power(a, b/2);
    if( b%2 != 0){
        return a*k*k;
    }
    else{
        return k*k;
    }
}

int main(){

    int a,b;
    cin>>a>>b;
    
    if((a<0 && b<0) || (a>0 && b>0)){
        cout<<multiply(abs(a), abs(b))<<endl;
    }
    else{
        cout<< -1 * multiply(abs(a), abs(b))<<endl;
    }
    // cout<<multiply(3,5)<<endl;
    cout<<power(2,4)<<endl;
    cout<<fastPow(2,4)<<endl;
    return 0;
}