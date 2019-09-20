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

int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head->next;
    }
    return l;
}

void deleteAtHead(Node* &head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next; 
    delete temp;
    return;
}

void deleteAtTail(Node* &head){
    if(head == NULL){
        return;
    }
    Node* prev;
    Node* temp = head;
    while(temp->next != NULL){
        prev= temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}

void deleteAtMiddle(Node* &head, int p){
    if(head == NULL){
        return;
    }
    else if(head->next == NULL){
        delete head;
        return;
    }
    else if(p>=length(head)){
        deleteAtTail(head);
    }
    else{
        int jump = 1;
        Node* temp = head;
        while(jump <= (p-1)){
            temp = temp->next;
            jump++;
        }
        Node* n = temp->next;
        n->next = NULL;
        temp->next = (temp->next)->next;
        delete n;
    }
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

    deleteAtTail(head);
    printList(head);
    deleteAtHead(head);
    printList(head);
    deleteAtMiddle(head, 5);
    printList(head);
    return 0;
}