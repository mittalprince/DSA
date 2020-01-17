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

void helper()
{
    int n;
    cin >> n;
    int pre[n], in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> in[j];
    }

    node *root = buildTree(pre, in, 0, n - 1);
    Pair p = largestBST(root);
    cout << p.size << endl;
}

int main(){
    helper();
}