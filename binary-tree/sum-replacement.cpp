#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;

    node(int d):data(d),left(NULL),right(NULL){}
};

node *buildTree(){
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int sumreplacement(node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int left = sumreplacement(root->left);
    int right = sumreplacement(root->right);
    int temp = root->data;
    root->data = left+right;
    return (root->data+temp);
}

void traversal(node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}
int main(){
    node *root = buildTree();
    int sum = sumreplacement(root);
    traversal(root);
    cout<<endl;
    return 0;
}