/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *curr = head, *next = head, *prev = NULL;
        while (curr)
        {
            // cout<<curr->val<<" ";
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode *r1 = l1, *r2 = l2;
        r1 = reverse(r1);
        r2 = reverse(r2);
        ListNode *temp1 = r1, *temp2 = r2;

        // cout<<temp1->val<<" "<<temp2->val;
        ListNode *prev = NULL;
        int t = 0, carry = 0;
        while (temp1 && temp2)
        {
            t = temp1->val + temp2->val + carry;
            carry = t / 10;
            t = t % 10;
            temp1->val = t;
            prev = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (carry)
        {
            if (!temp1 && !temp2)
            {
                prev->next = new ListNode(carry);
                l2 = reverse(r2);
                l1 = reverse(r1);
                return l1;
            }
        }
        if (temp2)
        {
            prev->next = temp2;
            // cout<<temp2->val;
            ListNode *temp = temp2;
            while (carry && temp2)
            {
                t = temp2->val + carry;
                carry = t / 10;
                t = t % 10;
                temp2->val = t;
                temp = temp2;
                temp2 = temp2->next;
            }

            if (carry && !temp2)
            {
                temp->next = new ListNode(carry);
            }
        }
        else
        {
            prev->next = temp1;
            ListNode *temp = temp1;
            while (carry && temp1)
            {
                t = temp1->val + carry;
                carry = t / 10;
                t = t % 10;
                temp1->val = t;
                temp = temp1;
                temp1 = temp1->next;
            }

            if (carry && !temp1)
            {
                temp->next = new ListNode(carry);
            }
        }
        // cout<<r1->val<<" "<<r1->next->val;
        l1 = reverse(r1);
        // l2 = reverse(r2);

        return l1;
    }
};

*/

class Solution
{
public:
    int getSize(ListNode *head)
    {
        if (head == NULL)
        {
            return 0;
        }
        ListNode *curr = head;
        int ct = 0;
        while (curr)
        {
            curr = curr->next;
            ct++;
        }

        return ct;
    }

    int addNumber(ListNode *l1, ListNode *l2, int diff)
    {
        if(l1 == NULL || l2 == NULL){
            return 0;
        }

        int sum = 0;
        if(diff > 0){
            sum = l1->val+ addNumber(l1->next, l2, diff-1);
        }
        else{
            sum = l1->val+l2->val+addNumber(l1->next, l2->next, diff);
        }
        l1->val = sum%10;
        return (sum/10);
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }

        int l1_size = getSize(l1);
        int l2_size = getSize(l2);
        int diff;

        ListNode *temp = NULL;
        if(l1_size < l2_size){
            diff = l2_size-l1_size;
            temp = l1;
            l1 = l2;
            l2 = temp;
        }
        else{
            diff = l1_size-l2_size;   
        }
        ListNode *ans = new ListNode(0);
        ans->next = l1;
        ans->val = addNumber(l1, l2, diff);
        
        if(ans->val){
            return ans;
        }
        else{
            return ans->next;
        }
    }
};
