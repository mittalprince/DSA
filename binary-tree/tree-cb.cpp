#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

class Pair{
    public:
    int ht;
    int dia;

    Pair():ht(0),dia(0){}
};

node* buildTree(){
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }   
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void preOrder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// bottom up traversal
void inOrder(node *root){
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// complexity is O(N)
int printHeight(node *root){
    if(root == NULL){
        return 0;
    }
    int ans = max(printHeight(root->left), printHeight(root->right))+1;
    return ans;
}

void levelOrder(node *root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void printkthLevel(node *root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    printkthLevel(root->left, k-1);
    printkthLevel(root->right, k - 1);
}

void printAllLevel(node *root){
    int h = printHeight(root);
    for(int i=1; i<=h; i++){
        printkthLevel(root, i);
        cout<<endl;
    }
}

// complexity is O(N^2)
int diameter(node *root){
    if(root == NULL){
        return 0;
    }
    int h1 = printHeight(root->left);
    int h2 = printHeight(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}

Pair fastDiameter(node *root){
    Pair p;
    if(root == NULL){
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.ht = max(left.ht, right.ht)+1;
    p.dia = max(left.ht+right.ht, max(left.dia, right.dia));

    return p;
}

void traversal(node *root){
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    printAllLevel(root);
}

void Diameter(node *root){
    cout << diameter(root) << endl;
    Pair p = fastDiameter(root);
    cout << p.ht << " " << p.dia << endl;
}

int sumReplacement(node *root){
    if(root == NULL){
        return 0;
    }
    
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
}
int main(){
    node *root = buildTree();
    int t = sumReplacement(root);
    preOrder(root);
}
