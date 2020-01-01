#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d):data(d),next(NULL){}
};

void printList(node* root){
    if(root == NULL){
        return;
    }
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<endl;
}

int main(){
    int n, temp;
    cin>>n;
    node* eh = NULL, *et = NULL, *oh = NULL, *ot = NULL;

    for(int i=0; i<n; i++){
        cin>>temp;
        if(temp&1){
            if(ot == NULL){
                oh = ot = new node(temp);
            }
            else{
                ot->next = new node(temp);
                ot = ot->next;
            }
        }
        else{
            if(et == NULL){
                eh = et = new node(temp);
            }
            else{
                et->next = new node(temp);
                et = et->next;
            }
        }
    }

    ot->next = eh;
    printList(oh);
}