/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int sum(TreeNode *A, bool left)
    {
        if (A == NULL)
        {
            return NULL;
        }
        if (!A->left && !A->right && left)
        {
            return A->val;
        }

        return sum(A->left, true) + sum(A->right, false);
    }
    int sumOfLeftLeaves(TreeNode *A)
    {
        if (A == NULL)
        {
            return 0;
        }
        return sum(A, false);
    }
};