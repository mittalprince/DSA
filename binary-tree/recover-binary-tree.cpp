/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode *A, vector<int> &ans, TreeNode *&prev){
    if(A == NULL){
        return;
    }
    inorder(A->left, ans, prev);
    if(prev && A->val < prev->val){
        if(ans.empty()){
            ans.push_back(prev->val);
            ans.push_back(A->val);
        }
        else{
            ans.push_back(A->val);
        }
    }
    prev = A;
    inorder(A->right, ans, prev);
    
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int>ans;
    if(A == NULL){
        return ans;
    }
    TreeNode *prev = NULL;
    inorder(A, ans, prev);
    if(ans.size() > 2){
        ans.erase(ans.begin()+1);
    }
    if(ans[0] > ans[1]){
        swap(ans[0], ans[1]);
    }
    return ans;
}
Blog