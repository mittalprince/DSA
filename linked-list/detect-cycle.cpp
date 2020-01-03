#include<iostream>
#include<unordered_map>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d):data(d),next(NULL){}
};

node* kthNode(node *root, int k){
    node* temp = root;
    if(temp == NULL){
        return temp;
    }
    for(int i=1; i<k; i++){
        temp = temp->next;
    }
    // cout<<temp->data<<endl;
    return temp;
}

void removeCycle(node* root){

    node *fst=root, *slw=root;
    fst = fst->next->next;
    slw = slw->next;
    while(1){
        if(slw == fst){
            break;
        }
        fst = fst->next->next;
        slw = slw->next;
    }

    if(slw == fst){
        slw = root;
        cout<<fst->data;
        while(fst->next != slw->next){
            slw = slw->next;
            fst = fst->next;
        }
        fst->next = NULL;
    }
}

void printList(node *root){
    if(root == NULL){
        return;
    }

    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<endl;
}

int main(){
    int temp = 0;
    node *root, *tail;
    unordered_map<int, int> m;
    int i=0;
    bool flag = false;
    cin>>temp;
    while(temp != -1){
        i++;
        if(m.find(temp) != m.end()){
            if(!flag){
                tail->next = kthNode(root, m[temp]);
                flag = true;
            }
        }
        else{
            m[temp] = i;
            if(tail == NULL){
                root = tail = new node(temp);
            }
            else{
                tail->next = new  node(temp);
                tail = tail->next;
            }
        }
        cin>>temp;
    }
    // node* t = 
    removeCycle(root);
    // cout<<t->data;
    printList(root);
}