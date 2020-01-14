#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;

    node(int d):data(d), left(NULL), right(NULL){}
};

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
void traversal(node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

void TreeFromArr(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *root = buildTreeFromArr(arr, 0, n - 1);
    traversal(root);
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

int main(){
    int n;
    cin>>n;
    int pre[n], in[n];
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }
    // cin>>n;
    for(int i=0; i<n; i++){
        cin>>in[i];
    }

    node *root = buildTree(pre, in, 0, n-1);
    traversal(root);
    cout<<endl;
}