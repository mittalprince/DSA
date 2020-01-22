#include<iostream>
using namespace std;

class node{
    public;
    int val;
    node *left, *right;

    node(int val):val(val), left(NULL), right(NULL){}
};

node* lca(node *root, int x, int y){
    if(root == NULL){
        return root;
    }

    if(root->val == x){
        return root;
    }
    if(root->val == y){
        return root;
    }

    node *left = lca(root->left, x, y);
    node *right = lca(root->right, x, y);

    if(left && right){
        return root;
    }

    return (left)?left: right;
}

bool findNode(node *root, int key){
    if(key == NULL){
        return false;
    }

    if(root->val == key){
        return true;
    }

    bool left = findNode(root->left, key);
    bool right = findNode(root->right, key);

    return (left||right);
}

int LCA(node *root, int B, int C){
    if(!findNode(root, B) || !findNode(root, C)){
        return -1;
    }
    node *ans = lca(root, B, C);
    return ans->val;
}

int main(){

}
