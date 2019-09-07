#include<iostream>
using namespace std;
typedef long long ll;

int pow(int a, int b){
    int pow = 1;

    while(b){
        if(b&1){
            pow *= a;
        }

        b = b>>1;
        a = a*a;
    }
    return pow;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b)<<endl;
    return 0;
}