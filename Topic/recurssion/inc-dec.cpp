#include<iostream>
using namespace std;

void increasing(int n){
    if(n==0){
        return;
    }
    increasing(n-1);
    cout<<n<<" ";
}

void decreasing(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    decreasing(n-1);
}
int main(){
    int n;
    cin>>n;
    increasing(n);
    cout<<endl;
    decreasing(n);
    cout<<endl;
    return 0;
}