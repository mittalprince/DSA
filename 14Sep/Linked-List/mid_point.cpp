#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

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

Node* midPoint(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head->next;

    while(fast_ptr != NULL && fast_ptr->next != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;
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
    Node* temp = midPoint(head);
    if(temp != NULL){
        cout<<temp->data<<endl;
    }
    else{
        cout<<"List Empty"<<endl;
    }
    return 0;
}