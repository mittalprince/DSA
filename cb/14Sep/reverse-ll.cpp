#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void reverse(Node* head){
    Node* c=head;
    Node* next = head->next;
    Node* p = nullptr;

    while(c != nullptr){
        next = c->next;
        c->next = p;
        p = c;
        c = next;
    }
}

int main(){

}