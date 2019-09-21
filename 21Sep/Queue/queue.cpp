#include<iostream>
#include"queue.h"

using namespace std;

int main(){
    Queue q;
    int n, temp;
    for(int i=1; i<=7; i++){
        q.push(i);
    }
    // cout<<q.full()<<endl;
    q.pop();
    q.push(8);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}