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
    TreeNode *trimBST(TreeNode *A, int L, int R)
    {
        if (A == NULL)
        {
            return NULL;
        }
        A->left = trimBST(A->left, L, R);
        A->right = trimBST(A->right, L, R);

        if (A->val < L)
        {
            TreeNode *temp = A->right;
            // delete A;
            return temp;
        }
        if (A->val > R)
        {
            TreeNode *temp = A->left;
            // delete A;
            return temp;
        }
        return A;
    }
};