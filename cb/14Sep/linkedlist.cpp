#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

        Node(int d){
            this->data = d;
            this->next = nullptr;
        }

        ~Node(){
            if(next!= nullptr){
                delete next;
            }
        }
};

void insert(Node* head, int p, int )