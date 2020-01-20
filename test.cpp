#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data),left(NULL),right(NULL){}
};

Node* flatten(Node* root){

    if(root == NULL){
        return NULL;
    }

    Node* left = flatten(root->left);
    Node* right = flatten(root->right);

    bool check = false;
    if(left){
        left->right = root;
        check = true;
    }
    if(right){
        root->right = right;
    }
    Node* head = NULL;
    if(check){
        head = left;
    }
    else{
         head = root;
        }

    return head;
}

void print(Node* head){
    if(head == NULL) return;

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->right;
    }

}

int main(){

    Node* root = new Node(5); 
    root->left = new Node(3); 
    root->right = new Node(7); 
    root->left->left = new Node(2); 
    root->left->right = new Node(4); 
    root->right->left = new Node(6); 
    root->right->right = new Node(8); 


    Node* ans = flatten(root);

    print(ans);    
}