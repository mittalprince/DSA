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

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    Node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
        return c;
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

Node* mergeSort(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mid = midPoint(head);
    Node* x = head;
    Node* y = mid->next;
    mid->next = NULL;

    x = mergeSort(x);
    y = mergeSort(y);

    return merge(x, y);
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 11);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 7);
    insertAtHead(head, 10);
    insertAtHead(head, 2);
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    printList(head);

    head = mergeSort(head);
    printList(head);
    return 0;
}
