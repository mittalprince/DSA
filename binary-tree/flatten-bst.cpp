#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d), left(NULL), right(NULL){}
};

class listNode{
    public:
    node *head, *tail;

    listNode():head(NULL),tail(NULL){}
};

node* Solution::flatten(node* A) {
    // Logic: each node’s right child points to the next node of a pre-order traversal
    /*
`        1
        / \
       2   5
      / \   \
     3   4   6
`

    1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

    */
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

   if(A == NULL){
       return A;
   }
   node *root = A;
   
   while(root){
       
       if(root->left){
           node *temp = root->left;
           
           while(temp->right){
               temp = temp->right;
           }
           temp->right = root->right;
           root->right = root->left;
           root->left = NULL;
       }
       root = root->right;
   }
   
   return A;

listNode flatten(node *root){
    listNode p;
    if(root ==NULL){
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        p.head = p.tail = root;
        return p;
    }

    listNode left = flatten(root->left);
    listNode right = flatten(root->right);

    if(left.head && right.head){
        left.tail->right = root;
        root->right = right.head;

        p.head = left.head;
        p.tail = right.tail;
    }
    else if(left.head){
        left.tail->right = root;

        p.head = left.head;
        p.tail = root;
    }
    else{
        root->right = right.head;

        p.head = root;
        p.tail = right.tail;
    }
 
    return p;     
}

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

node* buildTree(){
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
    cout << root->data << " ";
    traversal(root->left);
    traversal(root->right);
}

int main(){
    node *root = buildTree();
    traversal(root);
    cout<<endl;

    listNode head = flatten(root);
    node *temp = head.head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout<<endl;
}