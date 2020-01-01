#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d):data(d),next(NULL){}
};

void printList(node *root){
    if(root == NULL){
        return;
    }

    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<endl;
}

node* reverese(node *root){
    node* curr = root;
    node* next = root;
    node* prev = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool checkPalimdrome(node *root){
    if(root == NULL){
        return root;
    }

    node *fst=root, *slw=root, *prev_of_slw = NULL, *mid = NULL;
    while(fst != NULL && fst->next != NULL){
        fst = fst->next->next;
        prev_of_slw = slw;
        slw = slw->next;
    }

    if(fst != NULL){
        mid = slw;
        slw = slw->next;
    }
    node *sh = slw;
    slw = sh = reverese(sh);
    prev_of_slw->next = NULL;
    node *temp = root;

    bool ans = true;
    while(temp && sh){
        if(temp->data != sh->data){
            ans = false;
        }
        temp = temp->next;
        sh = sh->next;
    }

    slw = reverese(slw);
    if(mid){
        prev_of_slw->next = mid;
        mid->next = slw;
    }
    else{
        prev_of_slw->next = slw;
    }

    return ans;
}
int main(){
    int n,temp;
    cin>>n;
    node *root = NULL, *tail = NULL;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(tail == NULL){
            root = tail =  new node(temp);
        }
        else{
            tail->next = new node(temp);
            tail = tail->next;
        }
    }

    if(checkPalimdrome(root)){
        cout<<"True\n";
    }
    else{
        cout<<"False\n";
    }
}