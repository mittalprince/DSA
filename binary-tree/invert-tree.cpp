/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A){
        return A;
    }
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        
        if(temp->right && temp->left){
            TreeNode *swap = temp->left;
            temp->left = temp->right;
            temp->right = swap;
        }
        
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return A;
}
