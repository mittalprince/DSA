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
    temp->next = head;
    head = temp;
}

bool detectCycle(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;
    while(slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr){
            return true;
        }
    }
    return false;
}

void removeCycle(Node* &head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *slow_ptr = head;
    Node *fast_ptr = head;
    Node* temp;
    while (slow_ptr && fast_ptr && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
        {
            slow_ptr = head;
            break;
        }
    }
    
    while(slow_ptr != fast_ptr){
        slow_ptr = slow_ptr->next;
        temp = fast_ptr;
        fast_ptr = fast_ptr->next;
    }
    temp->next = NULL;
}

void printList(Node* head){
    if(head == NULL){
        return;
    }
    while(head != NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
}

int main(){

    Node* head = NULL;
    insert(head, 7);
    insert(head, 6);
    insert(head, 5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    printList(head);
    cout<<endl;
    // cout << head->next->next->next->next->next->next->data;
    head->next->next->next->next->next->next->next = head->next->next;
    if(detectCycle(head)){
        cout<<"Cycle exixt"<<endl;
        removeCycle(head);
        printList(head);
        cout<<endl;
    }
    else{
        cout<<"No cycle"<<endl;
    }
    return 0;
}