/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int check(TreeNode *A, TreeNode *B){
    if(A == NULL && B == NULL){
        return true;
    }
    if(A == NULL || B == NULL){
        return false;
    }
    
    bool ans = true;
    if(A->val != B->val){
        return false;
    }
    ans = ans && check(A->left, B->right) && check(A->right, B->left);
    return ans;
    
} 
int Solution::isSymmetric(TreeNode* A) {
    bool ans = true;
    if(A == NULL){
        return ans;
    }
    
    ans = check(A, A);
    return ans;
}
