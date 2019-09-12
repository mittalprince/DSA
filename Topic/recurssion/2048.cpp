#include<iostream>
using namespace std;

char spell[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void problem(int n){
    if(n == 0){
        return;
    }
    problem(n/10);
    cout<<spell[n%10]<<" ";
}
int main(){
    int n;
    cin>>n;
    problem(n);
    cout<<endl;
    return 0;
}