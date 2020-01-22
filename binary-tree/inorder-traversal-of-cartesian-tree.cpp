/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* build(vector<int> &A, int s, int e){
    if(s > e){
        return NULL;
    }
    int index;
    int max = INT_MIN;
    for(int i=s; i<=e; i++){
        if(max < A[i]){
            max = A[i];
            index = i;
        }
    }
    
    TreeNode *root = new TreeNode(max);
    root->left = build(A, s, index-1);
    root->right = build(A, index+1, e);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int s = 0, e = A.size()-1;
    TreeNode *ans = build(A, s, e);
    return ans;
}

/*

norder traversal : (Left tree) root (Right tree)

Note that the root is the max element in the whole array. Based on the info, can you figure out the position of the root in inorder traversal ? If so, can you separate out the elements which go in the left subtree and right subtree ?
Once you have the inorder traversal for left subtree, you can recursively solve for left subtree. Same for right subtree.

Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 

Given inorder traversal can you find the root here? What can you do once you get the root element and its left and right subtree?
*/