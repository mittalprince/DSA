#include<iostream>
using namespace std;

class node{
    public:
    int data, ht;
    node *left, *right;

    node(int data):data(data),ht(0),left(NULL),right(NULL){}
};

int height(node *root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right))+1;
}

int getBalancefactor(node *root){
    if(root == NULL){
        return 0;
    }
    return height(root->left)-height(root->right);
}

node* leftRotate(node *y){
    node *t1 = y->right;
    node *t2 = t1->left;

    t1->left = y;
    y->right = t2;

    y->ht = height(y);
    t1->ht = height(t1);

    return t1;
}

node* rightRotate(node *y){
    node *t1 = y->left;
    node *t2 = t1->right;

    t1->right = y;
    y->left = t2;

    t1->ht = height(t1);
    y->ht = height(y);

    return t1;
}

node *nextRightMost(node *root){
    if(root == NULL){
        return NULL;
    }
    while(root->left){
        root = root->left;
    }
    return root;
}

node* deletion(node *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = deletion(root->left, key);
    }
    else if(key > root->data){
        root->right = deletion(root->right, key);
    }
    else{
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            delete(temp);
        }
        else{
            node *replace = nextRightMost(root->right);
            root->data = replace->data;
            root->right = deletion(root->right, replace->data);
        }
    }

    if(root == NULL){
        return root;
    }
    root->ht = height(root);
    int bf = getBalancefactor(root);

    if (bf > 1 && getBalancefactor(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (bf < -1 && getBalancefactor(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (bf > 1 && getBalancefactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1 && getBalancefactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

node* insert(node *root, int key){
    if(root == NULL){
        return new node(key);
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
    }
    else{
        return root;
    }

    root->ht = height(root);
    int bf = getBalancefactor(root);

    if(bf > 1 && key < root->left->data){
        /*
        new key inserted in root->left left subtree
        */
        // left left case ---> rightRotation
        return rightRotate(root);
    }

    if(bf < -1 && key > root->right->data){
        // right right case ---> leftRotation;
        return leftRotate(root);
    }

    if(bf > 1 && key > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int n, temp;
    cin>>n;
    node *root = NULL;
    for(int i=0; i<n; i++){
        cin>>temp;
        root = insert(root, temp);
    }
    preorder(root);
    cout<<endl;
    int del;
    cin>>del;
    root = deletion(root, del);
    preorder(root);
    cout<<endl;
}