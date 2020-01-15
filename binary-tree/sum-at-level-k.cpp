#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d), left(NULL), right(NULL){}
};


node* buildTree(){
    int data, child;
    cin>>data>>child;

    node *root = new node(data);
    if(child == 0){
        return root;
    }

    if(child == 1){
        root->left = buildTree();
    }
    else{
        root->left = buildTree();
        root->right = buildTree();
    }

    return root;
}

int sumAtLevel(node *root, int k){
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    if(k == 0){
        sum += root->data;
    }
    
    int left = sumAtLevel(root->left, k-1);
    int right = sumAtLevel(root->right, k-1);

    sum += (left+right);
    return sum;
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
    traversal(root);
    cout<<endl;
    int k;
    cin>>k;
    int sum = sumAtLevel(root, k);
    cout<<sum<<endl;
    return 0;
}