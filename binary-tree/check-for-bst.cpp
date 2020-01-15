#include<iostream>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node *right, *left;

    node(int d):data(d),right(NULL),left(NULL){}
};

node* insert(node *root, int key){
    if(root == NULL){
        node *temp = new node(key);
        return temp;
    }

    if(root->data < key){
        root->right = insert(root->right, key);
    }
    else{
        root->left = insert(root->left, key);
    }
    return root;
}

node* buildTree(){
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

bool checkBst(node *root, int minV = INT_MIN, int maxV = INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root->data >= minV && root->data <= maxV && checkBst(root->left, minV, root->data) && checkBst(root->right, root->data, maxV)){
        return true;
    }
    return false;
}

int main(){
    node *root = buildTree();
    if(checkBst(root)){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }
}