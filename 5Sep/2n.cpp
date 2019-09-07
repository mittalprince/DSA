#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    if(n&(n-1)){
        cout<<"no"<<endl;
    }
    else
    {
        cout<<"yes"<<endl;
    }
    return 0;  
}

// To find whether a digit or number is power of 2 or not