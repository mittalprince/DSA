#include<iostream>
using namespace std;
#define max 1000000

int fibo(int n, int arr[]){
    
    if(n == 0 || n == 1){
        return n;
    }

    if(arr[n]){
        return arr[n];
    }

    int ans = fibo(n-1, arr) + fibo(n-2, arr);
    return arr[n] = ans;
}

int f(int n){
    int arr[max] = {0};

    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2]; 
    }

    return arr[n];
}
int main(){
    int n;
    cin>>n;
    int arr[max] = {0};
    cout<<fibo(n, arr);
    cout<<endl;
    cout<<f(n)<<endl;

    return 0;
}