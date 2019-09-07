#include<iostream>
using namespace std;
typedef long long ll;

int getSetBit(int n, int i){
    return (n&(1<<i)) >0? 1: 0;
}

int GetSetBit(int n, int i){
    return ((n>>i)&1)>0?1:0;
}
void setBits(int n, int i){
    n = (n|(i<<i));
}
int main(){
    
    return 0;
}
