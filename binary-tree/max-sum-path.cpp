/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        findMax(root, sum);
        return sum;
    }
    
    int findMax(TreeNode *node, int& maxSum){
        if(!node) return 0;
        
        int left = max(findMax(node->left, maxSum), 0);
        int right = max(findMax(node->right, maxSum), 0);
        int curSum = left + right + node->val;
        
        maxSum = max(maxSum, curSum);
        
        return node->val + max(left, right);
    }
};