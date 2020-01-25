/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;https://www.interviewbit.com/courses/1/topics/13/problems/kth-smallest-element-in-tree/hints/668/
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
    stack<TreeNode*>s;
    TreeNode *temp=A;
    int ans = 0;
    while(true){
        if(temp){
            s.push(temp);
            temp = temp->left;
        }
        else{
            if(s.empty()){
                break;
            }
            TreeNode *top = s.top();
            s.pop();
            B--;
            if(B == 0){
                ans = top->val;
                break;
            }
            temp = top->right;
        }
    }
    return ans;
}
