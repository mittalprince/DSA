/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Solution::t2Sum(TreeNode* A, int B) {
    if(A == NULL){
        return false;
    }
    stack<TreeNode*> s1, s2;
    TreeNode *temp1 = A, *temp2 = A;
    
     while(temp1->left){
        s1.push(temp1);
        temp1 = temp1->left;
    }
    while(temp2->right){
        s2.push(temp2);
        temp2 = temp2->right;
    }
    bool ans = false;
    while(temp1 != temp2){
        // cout<<a->val<<" "<<b->val<<endl;
        if(temp1->val+temp2->val == B){
            ans =  true;
            break;
        }
        else if(temp1->val+temp2->val < B){
            // TreeNode *top = s1.top();
            if(temp1->right){
                temp1 = temp1->right;
                while(temp1){
                    s1.push(temp1);
                    temp1 = temp1->left;
                }
            }
            temp1 = s1.top();
             s1.pop();
        }
        else{
            // TreeNode *top = s2.top();
            if(temp2->left){
                temp2 = temp2->left;
                while(temp2){
                    s2.push(temp2);
                    temp2 = temp2->right;
                }
            }
            temp2 = s2.top();
            s2.pop();
        }
    }
    
    return ans;
    
}


// Another Approach 

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
    bool findTarget(TreeNode* root, int k) {
        std::vector<int> values = {};
        std::stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            values.push_back(curr->val);
            curr = curr->right;
        }
        int left = 0;
        int right = values.size() - 1;
        while (left < right) {
            int sum = values[left] + values[right];
            if (sum > k)
                --right;
            else if (sum < k)
                ++left;
            else
                return true;
        }
        return false;
        
    }
    void inorder(TreeNode *root, vector<int> &inor)
    {
        if (!root)
            return;
        inorder(root->left, inor);
        inor.push_back(root->val);
        inorder(root->right, inor);
    }
};