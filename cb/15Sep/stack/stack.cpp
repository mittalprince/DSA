#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(NULL)
    {
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

void top(Node* head){
    if(head == NULL){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<head->data<<endl;
        return;
    }
}

void pop(Node* &head){
    if(head == NULL){
        cout<<"Satck is empty"<<endl;
        return;
    }
    if(head->next == NULL){
        cout<<head->data<<endl;
        delete head;
        return;
    }
    Node* temp = head;
    cout<<temp->data<<endl;
    head = temp->next;
    delete temp;
    return;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head);
    top(head);
    pop(head);
    printList(head);
    top(head);
    return 0;
}