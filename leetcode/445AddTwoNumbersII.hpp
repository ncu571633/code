You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

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
        int getLength(ListNode* h)
        {
            int i=0;
            while(h) {
                h=h->next;
                i++;
            }
            return i;
        }
        int addCarry(ListNode* h)
        {
            if (!h)
                return 0;
            h->val += addCarry(h->next);
            int ret = h->val / 10;
            h->val = h->val % 10;
            return ret;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int s1=getLength(l1);
            int s2=getLength(l2);
            if(s1<s2)
                return addTwoNumbers(l2, l1);
            if(!s2)
                return l1;
            ListNode* dummy = new ListNode(0);
            dummy->next = l1;
            for(int i=0; i<s1-s2; i++)
            {
                l1 = l1->next;
            }
            for(; l1; l1=l1->next, l2=l2->next)
            {
                l1->val += l2->val;
            }
            int val = addCarry(dummy);
            assert(!val);
            return (dummy->val) ? dummy: dummy->next;
        }
};
