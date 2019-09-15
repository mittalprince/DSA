#include<iostream>
using namespace std;
#define max 1000000

class stack{
    public:
    int arr[max];
    int top1;
    int top2;
    int N;
    stack(int n):top1(0),top2(n),N(n){}

    void push1(int x){
        if(top2-top1 > 1){
            top1++;
            arr[top1] = x;
        }
        else{
            cout<<"Cant performed"<<endl;
            return;
        }
    }
    void push2(int x){
        if(top2-top1 > 1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout<<"Cant performed"<<endl;
            return;
        }
    }

    void pop1(){
        if(top1 != -1){
            cout<<arr[top1]<<endl;
        }
        else{
            cout<<"Underflow"<<endl;
            return;
        }
    }
    void pop2(){
        if(top2 != N){
            cout<<arr[top2]<<endl;
        }
        else{
            cout<<"Underflow"<<endl;
            return;
        }
    }
    void print1(){
        if(top1 != -1){
            for(int i=0; i<=top1; i++){
                cout<<arr[i]<<" ";
            }
        }
        else{
            cout<<"Stack1 is empty"<<endl;
        }
    }

    void print2(){
        if(top2 != -1){
            for(int i=top2; i<N; i++){
                cout<<arr[i]<<" ";
            }
        }
        else{
            cout<<"Stack2 is empty"<<endl;
        }
    }
};

int main(){

    int n;
    cin>>n;
    stack s(n);
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(x == 1){
            s.push1(y);
        }
        else{
            s.push2(y);
        }
    }

    s.print1();
    cout<<endl;
    s.print2();
    cout<<endl;
    return 0;
}