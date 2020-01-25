/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int check(TreeNode *A, int currSum){
     if(A == NULL){
         return 0;
     }
     currSum = (currSum*10 + A->val)%1003;
     if(A->left == NULL && A->right == NULL){
         return currSum;
     }
     return (check(A->left, currSum)+check(A->right, currSum))%1003;
 }
int Solution::sumNumbers(TreeNode* A) {
    return check(A, 0);
}