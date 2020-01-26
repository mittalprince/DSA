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
    vector<TreeNode *> build(int low, int high)
    {
        if (low == high)
        {
            return {new TreeNode(low)};
        }
        else if (low > high)
        {
            return {nullptr};
        }
        vector<TreeNode *> res;
        for (int i = low; i <= high; ++i)
        {
            vector<TreeNode *> leftTree = build(low, i - 1);
            vector<TreeNode *> rightTree = build(i + 1, high);
            for (auto &leftnode : leftTree)
            {
                for (auto &rightnode : rightTree)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftnode;
                    root->right = rightnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (n < 1)
        {
            return {};
        }
        return build(1, n);
    }

    int numTrees(int n)
    {
        int dp[n + 1] = {1};
        int i, j;

        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};