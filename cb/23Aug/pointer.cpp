#include<iostream>

using namespace std;

void increment(int &p){
    (p)++;
    cout<<p<<endl;
}
int main(){

    int n = 10;
    increment(n);
    cout<<n<<endl;
    return 0;
}