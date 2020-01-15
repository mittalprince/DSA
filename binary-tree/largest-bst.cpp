#include<iostream>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

class Pair{
    public:
    int size, mx, mi, ans;
    bool isBst;

    Pair():ans(0),size(0),mx(INT_MIN),mi(INT_MAX),isBst(true){}
};

Pair largestBST(node *root){
    Pair p;
    if(root == NULL){
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        p.size = 1;
        p.mx = root->data;
        p.mi = root->data;
        p.isBst = true;
        p.ans = 1;

        return p;
    }

    Pair left = largestBST(root->left);
    Pair right = largestBST(root->right);

    if(root->data >= left.mx && root->data <= right.mi && left.isBst && right.isBst){
        p.mx = max(root->data, max(left.mx, right.mx));
        p.mi = min(root->data, min(left.mi, right.mi));

        p.size = left.size + right.size + 1;
        p.isBst = true;
    }
    else{
        p.size = max(left.size, right.size);
        p.isBst = false;
    }

    return p; 
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

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

int main(){
    node *root = buildTree();
    inOrder(root);
    cout<<endl;
    Pair p = largestBST(root);
    cout<<p.size<<endl;
}