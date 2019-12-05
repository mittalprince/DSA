// https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/

#include<iostream>
using namespace std;

unsigned int CountSetBits(unsigned int n){

    if(n == 0){
        return 0;
    }
    return ((n%2 == 0)? 0: 1)+CountSetBits(n/2);
}

unsigned int Driver(unsigned int n){
    int bitsCount = 0;
    for(int i=1; i<=n; i++){
        bitsCount += CountSetBits(i);
    }
    return bitsCount;
}
int main(){
    int n;
    cin>>n;
    cout<<Driver(n)<<endl;
    return  0;
}