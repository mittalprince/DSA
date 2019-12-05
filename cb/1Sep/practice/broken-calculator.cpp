#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int multiply(int res[], int res_size, int n){

    int carry = 0;
    for(int i=0; i<res_size; i++){
        int temp = res[i]*n+carry;
        res[i]= temp%10;
        carry = temp/10;
    }

    while(carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }

    return res_size;
}
void factorail(int n){

    int res[1000000];
    int res_size = 1;
    res[0] = 1;

    if(n==0 || n == 1){
        cout<<"1"<<endl;
        return;
    }

    for(int i=2; i<=n; i++){
        res_size = multiply(res, res_size, i);
    }

    for(int i=res_size-1; i>=0; i--){
        cout<<res[i];
    }
    cout<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    factorail(n);
    return 0;
}