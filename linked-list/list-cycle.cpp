/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    
    ListNode *fst=A, *slw=A;
    
    while(1 && slw && fst && fst->next){
        fst=fst->next->next;
        slw = slw->next;
        
        if(slw == fst){
            break;
        }
    }
    
    ListNode *ans = NULL;
    
    if(slw == fst){
        slw = A;
        while(slw != fst){
            slw = slw->next;
            fst = fst->next;
        }
        
        ans = new ListNode(fst->val);
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


/*


Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

*/