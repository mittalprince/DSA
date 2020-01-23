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

Node* getNextRight(Node *p)  
{  
    Node *temp = p->nextRight;  
    while (temp != NULL)  
    {  
        if (temp->left != NULL)  
            return temp->left;  
        if (temp->right != NULL)  
            return temp->right;  
        temp = temp->nextRight;  
    }  

    return NULL;  
}  
  
Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        Node *ans = root;
        while(root){
            Node *temp = root;
            
            while(temp){
                if(temp->left){
                    if(temp->right){
                        temp->left->next = temp->right;
                    }
                    else{
                        temp->left->next = getNextRight(temp);
                    }
                }
                if(temp->right){
                    temp->right->next = getNextRight(temp);
                }
                temp = temp->next;
            }
            
            if(root->left){
                root = root->left;
            }
            else if(root->right){
                root = root->right;
            }
            else{
                root = getNextRight(root);
            }
        }
        
        return ans;
    }