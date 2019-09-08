#include<iostream>
using namespace std;

int main(){
    int l,r;
    cin>>l>>r;

    int Xor = l^r;
    int m = 0;
    while(Xor){
        m++;
        Xor >>= 1;
    }
    cout<<(1<<m)-1<<endl;

    return 0;

}