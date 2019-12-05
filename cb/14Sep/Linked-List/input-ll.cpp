#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d):data(d),next(NULL){
    }


};

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

void buildList(Node* &head){
    int data;
    cin>>data;
    while(data != -1){
        insertAtTail(head, data);
        cin>>data;
    }
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

int main(){
    Node* head = NULL;
    buildList(head);
    printList(head);
    return 0;
}