/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        ListNode *r1 = l1, *prev;
        int carry = 0;
        while(l1 && l2){
            int t = l1->val + l2->val + carry;
            carry = t/10;
            t = t%10;
            l1->val = t;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(carry){
            if(!l2 && !l1){
                prev->next = new ListNode(carry);
                return r1;
            }
        }
        if(l2){
            prev->next = l2;
            ListNode* t1 = l2;
            while(carry && l2){
                int tt;
                tt = l2->val+carry;
                carry = tt/10;
                tt = tt%10;
                t1 = l2;
                l2->val = tt;
                l2 = l2->next;
            }

            if(carry){
                t1->next = new ListNode(carry);
            }
        }
        else {
            prev->next = l1;
            ListNode* t1 = l1;
            while(carry && l1){
                int tt;
                tt = l1->val+carry;
                carry = tt/10;
                tt = tt%10;
                t1 = l1;
                l1->val = tt;
                l1 = l1->next;
            }

            if(carry){
                t1->next = new ListNode(carry);
            }
        }
        
        return r1;
    }
    
    
};