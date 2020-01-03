#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data):data(data),next(NULL){}
};

node* swap(node *l1, node *l2){
    // cout<<l1->data<<" "<<l2->data<<endl;
    l1->next = l2->next;
    l2->next = l1;
    return l2;
}
node* swap(node* root){
    if(root == NULL || root->next == NULL){
        return root;
    }

    node *curr=root, *temp=NULL, *prev=NULL;

    while(curr && curr->next){
        curr = swap(curr, curr->next);
        if(temp == NULL){
            temp = curr;
        }
        else{
            prev->next = curr;
        }
        prev = curr->next;
        curr = curr->next->next;
    }

    return temp;
}

void printList(node* root){
    if(root == NULL){
        return;
    }

    while(root){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<"\n";
}
int main(){
    int n, temp;
    node *root=NULL, *tail=NULL;
    cin>>n;
    while(n--){
        cin>>temp;
        if(tail == NULL){
            root = tail = new node(temp);
        }
        else{
            tail->next = new node(temp);
            tail = tail->next;
        }
    }

    root = swap(root);
    printList(root);
}