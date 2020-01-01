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

// Node* kappend(Node* root, int k){
//     if(root == NULL || root->next == NULL){
//         return root;
//     }
//     Node* fst = root, *slw = root, *R = root;
    
//     for(int i=0; i<k; i++){
//         fst = fst->next;
//     }

//     while(fst->next != NULL){
//         fst = fst->next;
//         slw = slw->next;
//     }

//     Node* temp = slw->next;
//     slw->next = NULL;
//     root = temp;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }
//     temp->next = R;
//     return root;
// }

Node* kappend(Node* root, int n, int k){
    if(root == NULL || root->next == NULL){
        return root;
    }
    int t = n-k-1;
    Node* prev = root, *curr = root->next;

    while(t--){
        curr = curr->next;
        prev = prev->next;
    }

    Node* temp = root;
    root = curr;
    prev->next = NULL;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return root;
}
int main(){
    int n,k, temp;
    cin>>n;
    Node* root = NULL, *tail;
    if(n>0){
        cin>>temp;
        root = tail = new Node(temp);
        for(int i=1; i<n; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
    }
    cin>>k;
    if(k>=n){
        k = k%n;
    }
    if(k>0){
        root = kappend(root, n, k);
    }  
    printList(root);
    return 0;
}