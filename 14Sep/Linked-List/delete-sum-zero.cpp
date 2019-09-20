#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d):data(d),next(NULL){}
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

void printList(Node* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(head != NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
}

istream& operator>> (istream& is, Node* &head){
    int data;
    cin>>data;
    while(data != -1){
        // cout<<data<<endl;
        insertAtTail(head, data);
        cin>>data;
    }
    return is;
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
int main(){

    Node* head = NULL;
    cin>>head;
    printList(head);
    cout<<endl;
    cout<<length(head)<<endl;
}