#include<iostream>
#include<queue>
#include<map>
#include<iterator>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

void preOrder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(node *root){
    if(root == NULL){
        return;
    }
    vector<int> v;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            v.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

    vector<int>::iterator it = v.begin();
    for (; it != v.end(); it++)
    {
        cout << *it << " ";
    }
}

node* buildTree(){
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

void levelOrderZigzag(node *root){
    if(root == NULL){
        return;
    }

    stack<node*> s1;
    stack<node*> s2;

    s1.push(root);
    vector<int> v;
    while(!s1.empty() || !s2.empty()){

        while(!s1.empty()){
            node *temp = s1.top();
            s1.pop();
            v.push_back(temp->data);
            if(temp->left){
                s2.push(temp->left);
            }
            if(temp->right){
                s2.push(temp->right);
            }
        }

        while(!s2.empty()){
            node *temp = s2.top();
            s2.pop();
            v.push_back(temp->data);
            if (temp->right)
            {
                s1.push(temp->right);
            }
            if (temp->left)
            {
                s1.push(temp->left);
            }
        }
    }
    vector<int>::iterator it = v.begin();
    for(; it!= v.end(); it++){
        cout<<*it<<" ";
    }
}

int main(){
    node *root = buildTree();

    preOrder(root);
    cout<<endl;

    postOrder(root);
    cout<<endl;

    inOrder(root);
    cout<<endl;

    levelOrder(root);
    cout<<endl;

    levelOrderZigzag(root);
    cout<<endl;
}
