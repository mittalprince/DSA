class Solution
{
public:
    int a;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        a = 1;
        depth(root);
        return a - 1;
    }

    int depth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        a = max(a, l + r + 1);
        return max(l, r) + 1;
    }
};