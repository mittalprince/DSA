#include<iostream>
using namespace std;
 
class node{
    public:
    node *left, *right;
    int val;

    node(int val):val(val),left(NULL),right(NULL){}
};


int hasPathSum(node* A, int B) {
    if(A == NULL && B == 0){
       return true;
    }
    if(A == NULL){
        return false;
    }
    
    if ( A->val == B && A->left == NULL && A->right == NULL ) {
        return true;
    } 
    
    bool ans = 0;
    if(A->left)  
        ans = ans || hasPathSum(A->left, B-A->val);  
    if(A->right)  
        ans = ans || hasPathSum(A->right, B-A->val);  
  
    return ans;
}

int main(){
    node *root = new node(1000);
    root->left = new node(200);

    int ans = (hasPathSum(root, 1000));
    cout<<ans<<endl;
}