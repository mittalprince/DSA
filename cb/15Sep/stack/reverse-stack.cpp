#include<bits/stdc++.h>
using namespace std;

void transfer(stack<int> &s, stack<int> &temp, int n){
    for(int i=0; i<n; i++){
        temp.push(s.top());
        s.pop();
    }
}

void reverseStack(stack<int> &s){

    int n = s.size();
    stack<int> temp;
    for(int i=0; i<n; i++){
        int x = s.top();
        s.pop();
        transfer(s, temp, n-i-1);
        s.push(x);
        transfer(temp, s, n-i-1);
    }
}   

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}


void printAtBottom(stack<int> &s, int topElement){
    if(s.empty()){
        s.push(topElement);
        return;
    }
    int data = s.top();
    s.pop();
    printAtBottom(s, topElement);
    s.push(data);
}
void reverse(stack<int> &s){

    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverse(s);
    printAtBottom(s, x);
}

int main(){

    stack<int> s;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.push(x);
    }

    printStack(s);
    reverseStack(s);
    cout<<endl;
    printStack(s);
    cout<<endl;
    reverse(s);
    printStack(s);
    cout << endl;
    return 0;

}