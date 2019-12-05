#include<iostream>
using namespace std;
#define max 1000000

class stack{
    public: 
    int arr[max];
    int top;

    stack():top(-1){};

    void push(int data){
        top++;
        arr[top] = data;
    }

    void printtop(){
       if(top == -1){
           cout<<"Stack is empty"<<endl;
           return;
       }
       else{
           cout<<arr[top]<<endl;
       }
    }

    void pop(){
        if(top != -1){
            top--;
        }
        else{
            cout << "Stack is empty" << endl;
            return;
        }
    }

    void print(){
        if(top == -1){
            cout<<"Stack is empty";
            return;
        }
        else{
            printtop();
            top--;
            print();
        }
    }
};

int main(){
    int n;
    cin>>n;
    stack s;
    while(n){
        int x;
        cin>>x;
        s.push(x);
        n--;
    }
    s.printtop();
    cout << " ";
    s.pop();
    cout << endl;
    s.print();
    cout << endl;
    return 0;    


}