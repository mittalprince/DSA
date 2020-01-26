/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static const int fast = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
    long sum{0};

public:
    void recurssiveSumFinder(TreeNode *root)
    {
        if (!root)
            return;

        if (root->val % 2 == 0)
        {
            if (root->left && root->left->left)
                sum += root->left->left->val;

            if (root->left && root->left->right)
                sum += root->left->right->val;

            if (root->right && root->right->left)
                sum += root->right->left->val;

            if (root->right && root->right->right)
                sum += root->right->right->val;
        }

        recurssiveSumFinder(root->left);
        recurssiveSumFinder(root->right);
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        sum = 0;
        recurssiveSumFinder(root);

        return sum;
    }
};