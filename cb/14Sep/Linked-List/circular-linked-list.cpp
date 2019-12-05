#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(int d):data(d),next(NULL){}
};

void insert(Node* &head, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        head->next = head;
        return;
    }

    Node* C = head;
    while(C->next != head){
        C = C->next;
    }
    C->next = temp;
    temp->next = head;
}

void printList(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<"-->";
    Node *temp = head->next;
    while(temp!= head){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}

Node* getNode(Node* head, int data){
    Node* temp = head;
    while(temp->next != head){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    if(temp->data == data){
        return temp; 
    }
    return NULL;
}

void deleteNode(Node* &head, int data){
    Node* del = getNode(head, data);
    if(del == NULL){
        cout<<"Not present"<<endl;
        return;
    }
    if(head == del){
        head = head->next;
    }
    Node* temp = head;
    while(temp->next != del){
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
    return;

}
int main(){
    Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    printList(head);
    cout<<endl;
    deleteNode(head, 5);
    printList(head);
    cout<<endl;
    deleteNode(head, 1);
    printList(head);
    cout << endl;
    return 0;
}