int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL){
        return true;
    }
    if(A == NULL || B == NULL){
        return false;
    }
    bool ans = true;
    
    if(A->val != B->val){
        ans = false;
    }
    
    ans = ans && isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    return ans;
}