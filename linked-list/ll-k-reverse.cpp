#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int d){
        data = d;
        next = NULL;
    }
};


Node* ll_Reverse(Node* root, int k){
    if(root == NULL){
        return NULL;
    }
    Node* tail = root;

    Node *curr = root;
    Node *next = root;
    Node *prev = NULL;

    for(int i=0; i<k; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    if(curr!=NULL){
        tail->next = ll_Reverse(curr, k);
    }
    return prev;

}

void printList(Node *root){
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

    Node* root = NULL, *tail = NULL;
    int n, temp, k;
    cin>>n>>k;
    cin>>temp;
    root = tail = new Node(temp);

    for(int i=1; i<n; i++){
        cin>>temp;
        Node* t = new Node(temp);
        tail->next = t;
        tail = t;
    }

    root = ll_Reverse(root, k);
    printList(root);

    return 0;
}
