#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d):data(d),next(NULL){}
};

node* kthElement(node* root, int k){
    if(k<=1 && (root == NULL || root->next == NULL)){
        return root;
    }
    node *fst, *slw;
    fst = slw = root;
    for(int i=0; i<=k; i++){
        fst = fst->next;
    }
    while(fst != NULL){
        fst = fst->next;
        slw = slw->next;
    }
    return slw;
}

int main(){
    int temp = 0, k;
    node *root = NULL, *tail = NULL;
    cin>>temp;
    while(temp != -1){
        if(tail == NULL){
            root = tail = new node(temp);
        }
        else{
            tail->next = new node(temp);
            tail = tail->next;
        }
        cin>>temp;
    }

    cin>>k;
    node* t = kthElement(root, k);
    cout<<t->data<<"\n";
}