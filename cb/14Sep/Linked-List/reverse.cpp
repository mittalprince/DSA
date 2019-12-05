#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node():data(0),next(NULL){}

    Node(int d):data(d),next(NULL){
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printList(Node* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(head != NULL){
        cout<<head->data<<"-->";
        head= head->next;
    }
    cout<<endl;
}

void reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printList(prev);
}

Node* reverseRec(Node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }

    Node* smallHead = reverseRec(head->next);
    Node* C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head);
    // reverseList(head);
    head = reverseRec(head);
    printList(head); 
    return 0;
}