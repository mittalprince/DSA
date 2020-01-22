/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  
TreeNode* build(vector<int>&A, vector<int>&B, int s, int e, int &i){

    if(s > e){
        return NULL;
    }
    TreeNode *root = new TreeNode(B[i]);
    int index = -1;
    for(int j=s; j<=e; j++){
        if(A[j] == B[i]){
            index = j;
            break;
        }
    }
    i--;
    if(index != -1){
        root->right = build(A, B, index+1, e, i);
        root->left = build(A, B, s, index-1, i);
    }
    return root;
    // return NULL;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B){
    int s = 0;
    int e = A.size()-1;
    int index = e;
    TreeNode *root = build(A, B, s, e, index);
    return root;
}
