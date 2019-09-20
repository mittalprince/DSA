#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* down;

    Node(int d):data(d),next(NULL),down(NULL){}
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->down = head;
    head = temp;
}
void printLisT(Node* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    while(head != NULL){
        cout<<head->data<<"-->";
        head = head->down;
    }
}

Node* merge(Node* &a, Node* &b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    Node* c;
    if(a->data < b->data){
        c = a;
        c->down = merge(a->down, b);
    }
    else{
        c = b;
        c->down = merge(a, b->down);
    }

    return c;
}

Node* flatten(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* a = flatten(head->next);
    Node* c = merge(head, a);
    return c;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 30);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    printLisT(head);
    cout<<endl;
    insertAtHead(head->next,20);
    insertAtHead(head->next, 10);
    printLisT(head->next);
    cout << endl;
    insertAtHead(head->next->next, 50);
    insertAtHead(head->next->next, 22);
    insertAtHead(head->next->next, 19);
    printLisT(head->next->next);
    cout << endl;
    insertAtHead(head->next->next->next, 45);
    insertAtHead(head->next->next->next, 40);
    insertAtHead(head->next->next->next, 35);
    insertAtHead(head->next->next->next, 20);
    printLisT(head->next->next->next);
    cout << endl;

    head = flatten(head);
    printLisT(head);
    cout<<endl;
    return 0;
}