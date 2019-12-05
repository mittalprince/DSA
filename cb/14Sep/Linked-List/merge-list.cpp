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

Node* merge(Node* a, Node* b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    Node *c ;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
        return c;
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 13);
    insertAtHead(head, 11);
    insertAtHead(head, 9);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    printList(head);
    Node *head1 = NULL;
    insertAtHead(head1, 14);
    insertAtHead(head1, 12);
    insertAtHead(head1, 10);
    insertAtHead(head1, 8);
    insertAtHead(head1, 6);
    insertAtHead(head1, 4);
    insertAtHead(head1, 2);
    printList(head1);

    Node* C = merge(head, head1);
    printList(C);
    return 0;
}
