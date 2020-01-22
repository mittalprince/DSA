#include<iostream>
#include<vector>
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

void check(node *A, int B, vector<vector<int> >&ans, vector<int> &temp){
    if(A == NULL){
        return;
    }
    
    temp.push_back(A->val);
    if(A->left == NULL && A->right == NULL && A->val == B){
       ans.push_back(temp);
       temp.pop_back();
        return;
    }
    
    check(A->left, B-A->val, ans, temp);
    check(A->right, B-A->val, ans, temp);
    temp.pop_back();
    return;
}
vector<vector<int> > pathSum(node* A, int B) {
    vector<int>temp;
    vector<vector<int> > ans;
    check(A, B, ans, temp);
    return ans;
}

int main(){
    node *root = new node(1000);
    root->left = new node(200);

    int ans = (hasPathSum(root, 1000));
    cout<<ans<<endl;
}