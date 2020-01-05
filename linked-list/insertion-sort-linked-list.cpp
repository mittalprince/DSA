#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d):data(d),next(NULL){}
};

void printList(node *head){
    if(head == NULL){
        return;
    }

    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

node* sortInsert(node *sorted, node *new_node){
    if(sorted == NULL || sorted->data >= new_node->data){
        new_node->next = sorted;
        sorted = new_node;
    }
    else{
        node* temp = sorted;
        while(temp->next && temp->next->data < new_node->data){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    // printList(sorted);
    return sorted;
}

node* insertionSort(node *head){
    node *sorted = NULL;

    if(head == NULL || head->next == NULL){
        return head;
    }

    node *curr = head, *temp=NULL;

    while(curr){
        temp = curr->next;
        sorted = sortInsert(sorted, curr);
        curr = temp;
    }
    
    return sorted;
}

int main(){

    int n, temp;
    node *root, *tail=NULL;
    cin>>n;
    while(n--){
        cin>>temp;
        if(tail == NULL){
            root = tail = new node(temp);
        }
        else{
            tail->next = new node(temp);
            tail = tail->next;
        }
    }
    root = insertionSort(root);
    printList(root);
}



