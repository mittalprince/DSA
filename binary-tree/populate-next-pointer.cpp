/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    q.push(NULL);
    
    TreeLinkNode *prev = NULL;
    while(!q.empty()){
        TreeLinkNode *temp = q.front();
        q.pop();
        
        if(temp){
            if(prev){
                prev->next = temp;
            }
            prev = temp;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else{
            if(!q.empty()){
                prev = NULL;
                q.push(NULL);
            }
        }
    }
}