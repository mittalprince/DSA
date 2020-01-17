#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *right, *left;

    node(int d):data(d),left(NULL),right(NULL){}
};

void kthNodesDown(node *root, int k){
    if(root == NULL || k < 0){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    kthNodesDown(root->left, k-1);
    kthNodesDown(root->right, k-1);
}

int allKthDistanceNodes(node *root, node *target, int k){
    if(root == NULL){
        return -1;
    }

    // if the root node is target node we print all kth distance node from root (all nodes lie below root)
    if(root == target){
        kthNodesDown(root, k);
        return 0;
    }

    // it means target node found in left subtree and it has left(int) distance from root->left node
    int left = allKthDistanceNodes(root->left, target, k);

    if(left != -1){
        // enter only if target found in let subtree

        // we check if left+1 == k, i.e present root node is at k distance from target node (in upper tree)
        if(left+1 == k){
            cout<<root->data<<" ";
        }
        else{
            // we print all nodes which are k-left-2 distance apart from root->right (or root ke right subtree mein, in below tree)
            /* 
            now as target node is at left distance from root->left, so to print all node which are actulay k distance
            apart from target node, we have k-left and extra -2 is for as root->right is two edge apart from root->left
            */

            kthNodesDown(root->right, k-left-2);
        }
        return 1+left;
    }

    int right = allKthDistanceNodes(root->right, target, k);
    if(right != -1){
        if(right+1 == k){
            cout<<root->data<<" ";
        }
        else{
            kthNodesDown(root->left, k-right-2);
        }
        return 1+right;
    }

    return -1;
}

int findIndex(int arr[], int s, int e, int key)
{
    int idx = -1;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] == key)
        {
            idx = i;
            return idx;
        }
    }
    return idx;
}

node *buildTree(int pre[], int in[], int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return NULL;
    }

    int idx = findIndex(in, s, e, pre[i]);
    i++;
    if (idx != -1)
    {
        node *root = new node(in[idx]);
        root->left = buildTree(pre, in, s, idx - 1);
        root->right = buildTree(pre, in, idx + 1, e);
        return root;
    }
    else
    {
        return NULL;
    }
}

void traversal(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

node* findNode(node *root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }
    node *left = findNode(root->left, key);
    node *right = findNode(root->right, key);

    if(left){
        return left;
    }
    if(right){
        return right;
    }

    return NULL;
}

void helper()
{   
    int n;
    cin>>n;
    int pre[n], in[n];
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }
    for(int j=0; j<n; j++){
        cin>>in[j];
    }

    node *root = buildTree(pre, in, 0, n-1);
    // traversal(root);
    // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int data, k;
        cin >> data >> k;
        node *target = findNode(root, data);
        int temp = allKthDistanceNodes(root, target, k);
        cout << endl;
    }
}

int main(){
    helper();
}