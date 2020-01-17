#include<iostream>
using namespace  std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

node *buildTreeFromArr(int arr[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) >> 1;
    node *root = new node(arr[mid]);
    root->left = buildTreeFromArr(arr, s, mid - 1);
    root->right = buildTreeFromArr(arr, mid + 1, e);

    return root;
}

void replaceNodeData(node *root){
    static int sum = 0;
    if(root == NULL){
        return ;
    }
    replaceNodeData(root->right);
    sum += root->data;
    root->data = sum;
    replaceNodeData(root->left);

    // return root->data+left;
}

void traversal(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

void helper(){
    int n,data;
    cin>>n;
    int arr[n];
    node *root = NULL;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    root = buildTreeFromArr(arr, 0, n-1);
    replaceNodeData(root);
    traversal(root);
    cout<<endl;
}
int main(){
    helper();
}   