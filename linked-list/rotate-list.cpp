/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* root, int B) {
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    ListNode *fst=root, *slw=root;
    int len = 1;
    while(fst->next){
        len++;
        fst = fst->next;
    }
    
    int t = len - (B%len);
    if(t == len){
        return root;
    }
    
    ListNode* prev;
    while(t--){
       prev = slw;
       slw = slw->next;
    }
    
    ListNode *temp = prev->next;
    prev->next = NULL;
    fst->next = root;
    root = temp;
    
    return root;
}
