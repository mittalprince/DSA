#include<iostream>
#include<queue>
#include<map>
#include<iterator>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

int x = 0;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};


vector<int> inorderTraversal(node* A) {
    vector<int> ans;
    stack<node*> s;
    node *temp = A;
    while(true){
        if(temp){
            s.push(temp);
            temp = temp->left;
        }
        else{
            if(s.empty()){
                break;
            }
            node *top = s.top();
            s.pop();
            ans.push_back(top->val);
            temp = top->right;
        }
    }
    return ans;
}

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

node *insert(node *&root)
{

    if (x == 0)
    {
        int k;
        cin >> k;
        x++;
        root = new node(k);
        //cout<<k<<endl;
        root->left = insert(root->left);
        root->right = insert(root->right);
        return root;
    }

    string s = "abc";
    cin >> s;
    if (s != "abc")
    {

        if (s == "true")
        {
            int d;
            cin >> d;
            //cout<<d<<" "<<s<<endl;
            node *nn = new node(d);
            nn->left = insert(nn->left);
            nn->right = insert(nn->right);
            return nn;
        }

        else
        {
            return root;
        }
    }

    return root;
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

void helper(){
    node *root = buildTree();
    preOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;

    inOrder(root);
    cout << endl;

    levelOrder(root);
    cout << endl;

    levelOrderZigzag(root);
    cout << endl;
}

int main(){
    node *root = insert(root);
    levelOrderZigzag(root);
    cout<<endl;
}

