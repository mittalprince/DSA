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

bool isSymmetric(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    q.push(A);
    
    while(!q.empty()){
        TreeNode *temp1 = q.front();
        q.pop();
        TreeNode *temp2 = q.front();
        q.pop();
        if(!temp1 && !temp2){
            continue;
        }
        if(!temp1 || !temp2){
            return false;
        }
        if(temp1->val != temp2->val){
            return false;
        }
        q.push(temp1->left);
        q.push(temp2->right);
        q.push(temp1->right);
        q.push(temp2->left);  

    }
    
    return true;
}