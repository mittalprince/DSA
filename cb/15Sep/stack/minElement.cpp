#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    stack<int> s1, s2;
    int x;
    cin>>x;
    s1.push(x);
    s2.push(x);

    for(int i=1; i<n; i++){
        cin>>x;
        s1.push(x);
        if(x <= s2.top()){
            s2.push(x);
        }
    }

    cout<<s2.top()<<endl;
    int q;
    cin>>q;
    while(q--){
        if(s1.top() == s2.top()){
            s1.pop();
            s2.pop();
        }
        else{
            s1.pop();
        }

        cout<<s2.top()<<endl;
    }
    return 0;
}