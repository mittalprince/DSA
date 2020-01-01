/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    map<int, int>m;
    ListNode* temp = A;
    ListNode* prev = A;
    while(temp != NULL){
        if(m.find(temp->val) == m.end()){
            m[temp->val]++;
            prev = temp;
            temp = temp->next;
        }
        else{
            ListNode *t = temp;
            if(temp->next){
                prev->next = temp->next;
                // prev = prev->next;
                temp = temp->next;
            }
            else{
                prev->next = NULL;
                temp = NULL;
            }
            delete t;
        }
        // prev = temp;
        // temp = temp->next;
    }
    
    return A;
}
