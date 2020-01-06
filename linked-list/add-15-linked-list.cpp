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

int add15(node *root, int val){
    if(root == NULL){
        return val;
    }

    int res = root->data + add15(root->next, val);
    root->data = res%10;
    return res/10;
}

node* helper(node *root, int val){
    int carry = 0;
    carry = add15(root, val);

    if(carry){
        node *temp = new node(carry);
        temp->next = root;
        root = temp;
    }

    return root;
}

int main(){
    int n,temp, no;
    cin>>n>>no;
    node *root, *tail = NULL;
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

    root = helper(root, no);
    printList(root);
}