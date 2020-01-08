/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    long long getVal(ListNode *head, int &ct)
    {
        if (head->val == 1 && head->next == NULL)
        {
            return 1;
        }
        if (head->val == 0 && head->next == NULL)
        {
            return 0;
        }

        long long ans = 0;
        if (head->val && ct >= 0)
        {
            ans = (1 << (ct - 1));
        }
        int len = ct - 1;
        ans += getVal(head->next, len);
        return ans;
    }
    int getSize(ListNode *head)
    {
        if (head == NULL)
        {
            return 0;
        }
        int ct = 0;
        ListNode *curr = head;
        while (curr)
        {
            curr = curr->next;
            ct++;
        }
        return ct;
    }

    int getDecimalValue(ListNode *head)
    {
        if (head == NULL)
        {
            return 0;
        }

        int len = getSize(head);
        // cout<<len;
        ListNode *temp = head;
        long long ans = getVal(temp, len);

        return ans;
    }
};