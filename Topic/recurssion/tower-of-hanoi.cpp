#include<iostream>
using namespace std;

void TOH(int n, char s, char d, char a){
    if(n == 1){
        cout << "Move disk 1 fromn " << s << " to " << d << endl;
        return;
    }
    TOH(n-1, s, a, d);
    cout << "Move disk " << n << " from " << s << " to " << d << endl;
    TOH(n-1, a, d, s);
}

int totalSteps(int n){
    return (1<<n)-1;
}

int main(){
    int n;
    cin>>n;
    cout<<totalSteps(n)<<endl;
    TOH(n, 'A', 'B', 'C');
    return 0;
}