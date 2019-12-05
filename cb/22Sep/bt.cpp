#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int d):data(d),left(NULL),right(NULL){}
};

Node* buildTree(){
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPost(Node* root){
    if(root == NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

void printKthLevel(Node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void printPre(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);

    return l+r+1;
}

void BFS(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        if(temp == NULL){
            cout<<"\n";
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main(){

    Node* root = NULL;
    root = buildTree();
    printPre(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
    printPost(root);
    cout<<endl;
    printKthLevel(root, 3);
    cout<<endl;
    BFS(root);
    cout<<endl;
    return 0;
}