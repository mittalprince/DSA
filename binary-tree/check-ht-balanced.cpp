#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

int x = 0;

class Pair{
    public:
    int ht;
    bool balanced;

    Pair():ht(0),balanced(true){}
};

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

Pair checkBalanced(node *root){
    Pair p;
    if(root == NULL){
        return p;
    }

    Pair l = checkBalanced(root->left);
    Pair r = checkBalanced(root->right);

    p.ht = max(l.ht, r.ht)+1;

    if(abs(l.ht-r.ht) <= 1 && l.balanced && r.balanced){
        p.balanced = true;
    }
    else{
        p.balanced = false;
    }
    return p;
}

int main(){
    node *root = insert(root);

    Pair p = checkBalanced(root);
    if(p.balanced){
        cout<<"true\n";
    }
    else{
        cout<<"false\n";
    }
    return 0;
}