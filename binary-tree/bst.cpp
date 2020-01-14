#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int d) : data(d), left(NULL), right(NULL) {}
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
        root->right = insert(root->right, key);
    }
    return root;
}

node* build(){
    int data;
    cin>>data;

    node *root = NULL;
    while(data != -1){
        root = insert(root, data);
        cin>>data;
    }
    return root;
}

void traversal(node *root){
    if(root == NULL){
        return;
    }
    
    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
}

// complexity is height of tree log(n) <= h <= n
// height can be log(n) in best case i.e when tree is balanced
// height can be n in worst case i.e not balanced or it is skewed tree
node* search(node *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

node* deleteNode(node *root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data > key){
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if(root->data == key){
        // 1. if node is lead node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        // 2. if node has one child
        if(root->left && root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 3. if this node has both children
        /*
            1. find the first successor or predessor this node
            2. replace root->data with this node
            3. Delete this node from root->right subtree or root->left subtree (in case predessor)
        */

       node *replace = root->right;
       while(replace->left){
           replace = replace->left;
       }
       root->data = replace->data;
       root->right = deleteNode(root->right, replace->data);
       
       return root;
    }
    else{
        root->right = deleteNode(root->right, key);
        return root;
    }

}
int main(){
    node *root = build();
    traversal(root);
    cout<<endl; 

    int s;
    cin>>s;
    node *found = search(root, s);

    if(found != NULL){
        cout<<"yes\n";
        root = deleteNode(root, s);
        traversal(root);
        cout<<endl;
    }
    else{
        cout<<"no\n";
    }

}
