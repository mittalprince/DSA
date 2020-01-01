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

// Node* ReverseItr(Node* root, int n, int k){
//     int loop = n/k;
//     Node *newHead = NULL;
//     Node* temp = root;
//     while(loop--){
//         // temp = root;
//         Node* curr = root;
//         Node* next = root->next;
//         Node* prev = NULL;
//         int ct = k;
//         while(curr && ct--){
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         if(newHead == NULL){
//             newHead = prev;
//         }
//         else if(curr != NULL){
//             temp->next = prev;
//             temp = curr;
//             cout<<"data "<<curr->data<<" "<<prev->data<<endl;
//         }
//         // if(curr != NULL){
//         //     root->next = prev;
//         // }
//         root = curr;
//     }

//     return newHead;
// }

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

    // root = ll_Reverse(root, k);
    root = ReverseItr(root, n, k);
    printList(root);

    return 0;
}

/*

Node* reverse(Node* root, int k){
    Node* temp = root;

    Node* curr = temp;
    Node* next = temp->next;
    Node* prev = NULL;

    while(k--){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // root = prev;
    temp->next = curr;
    // cout<<"HHHHH";
    // printList(prev);
    return curr;

}
void ll_k_Reverse(Node* &root, int n, int k){

    int loop = n/k;
    Node* temp = root, *t = NULL;
    while(loop--){
        printList(temp);
        temp = reverse(temp, k);
        printList(temp);
        // printList(root);
        
    }
    cout<<"ANSSS";
    printList(root);
}
*/