#include<iostream>
#include<vector>
#include<iterator>
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
    if(key <= root->data){
        root->left = insert(root->left, key);
    }
    else{
        root->right =insert(root->right, key);
    }
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

void printKey(node *root, int k1, int k2, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(k1 < root->data){
        printKey(root->left, k1, k2, ans);
    }
    if(root->data >= k1 && root->data <= k2){
        ans.push_back(root->data);
    }
    if(k2 > root->data){
        printKey(root->right, k1, k2, ans);
    }
}

void buildTree(){
    int t;
    cin>>t;
    while(t--){
        int n, data, k1, k2;
        node *root = NULL;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>data;
            root = insert(root, data);
        }
        cin>>k1>>k2;

        traversal(root);
        cout<<endl;

        vector<int> ans;
        printKey(root, k1, k2, ans);

        vector<int>::iterator it = ans.begin();
        for(; it!= ans.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

int main(){
    buildTree();
    return 0;
}