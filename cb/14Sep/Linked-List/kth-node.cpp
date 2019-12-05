#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d):data(d),next(NULL){}
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(data);
    return;
}

void printList(Node* head){
    if(head == NULL){
        return;
    }

    while(head != NULL){
        cout<<head->data<<"-->";
        head= head->next;
    }
}

int length(Node* head){
    if(head == NULL){
        return 0;
    }
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node* kthNode(Node* head, int index){
    if(head == NULL){
        return head;
    }

    if(index>= length(head)){
        return head;
    }
    int j=0;
    Node* fast_ptr = head;
    Node* slow_ptr = head;
    while(j<index){
        j++;
        fast_ptr = fast_ptr->next;
    }
    cout<<fast_ptr->data<<endl;
    while(fast_ptr != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    return slow_ptr;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head);
    cout<<endl;
    Node* temp = kthNode(head, 3);
    if( temp != NULL){
        cout<<temp->data<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}