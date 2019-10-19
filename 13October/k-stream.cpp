#include<bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> >p){
    while(!p.empty()){
        int temp = p.top();
        cout<<temp<<" ";
        p.pop();
    }
    cout<<endl;
}

int main(){
    int no;
    priority_queue<int, vector<int>, greater<int> > pq;
    int cs = 0;
    int k = 3;
    while(scanf("%d", &no) != EOF){
        if(no == -1){
            printHeap(pq);
            continue;
        }
        if(cs<k){
            pq.push(no);
            cs+=1;
        }
        else if(no > pq.top()){
            pq.pop();
            pq.push(no);
        }
    }


}