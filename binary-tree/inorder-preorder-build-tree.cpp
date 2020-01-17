#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;

    node(int d):data(d), left(NULL), right(NULL){}
};

void preOrder(node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

node* buildTreeFromArr(int arr[], int s, int e){
    if(s > e){
        return NULL;
    }
    int mid = (s+e)>>1;
    node *root = new node(arr[mid]);
    root->left = buildTreeFromArr(arr, s, mid-1);
    root->right = buildTreeFromArr(arr, mid+1, e);

    return root;
}

void TreeFromArr(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *root = buildTreeFromArr(arr, 0, n - 1);
    cout << endl;
}

int findIndex(int arr[], int s, int e, int key){
    int idx = -1;
    for(int i=s; i<=e; i++){
        if(arr[i] == key){
            idx = i;
            return idx;
        }
    }
    return idx;
}

node* buildTree(int pre[], int in[], int s, int e){
    static int i = 0;
    if(s > e){
        return NULL;
    }

    int idx = findIndex(in, s, e, pre[i]);
    i++;
    if(idx != -1){
        node *root = new node(in[idx]);
        root->left = buildTree(pre, in, s, idx-1);
        root->right = buildTree(pre, in, idx+1, e);
        return root;
    }
    else{
        return NULL;
    }
}

void traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
        if (f->left != NULL && f->right != NULL)
        {
            cout << f->left->data << " => " << f->data << " <= " << f->right->data << endl;
        }
        else if (f->left != NULL && f->right == NULL)
        {
            cout << f->left->data << " => " << f->data << " <= END" << endl;
        }
        else if (f->left == NULL && f->right != NULL)
        {
            cout << "END => " << f->data << " <= " << f->right->data << endl;
        }
        else
        {
            cout << "END => " << f->data << " <= END" << endl;
        }
        q.pop();
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return;
}


int main(){
    int n;
    cin>>n;
    int pre[n], in[n];
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>in[i];
    }

    node *root = buildTree(pre, in, 0, n-1);
    traversal(root);
}