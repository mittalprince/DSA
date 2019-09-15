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

int length(Node* head){
    if(head == NULL){
        return 0;
    }
    int l = 0 ;
    while(head != NULL){
        l++;
        head = head->next;
    }
    return l;
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

void insertAtMiddle(Node* &head,  int p, int data){
    if(head == NULL || p==0){
        insertAtHead(head, data);
    }
    else if(p>=length(head)){
        insertAtTail(head, data);
    }
    else{
        int jump = 1;
        Node* temp = head;
        while(jump<= (p-1)){
            temp  = temp->next;
            jump++;
        }
        Node* N = new Node(data);
        N->next = temp->next;
        temp->next = N;
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
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 1);
    insertAtTail(head, 6);
    insertAtMiddle(head, 1, 2);
    insertAtMiddle(head, 2, 3);
    insertAtMiddle(head, 6, 7);
    printList(head);
    return 0;
}