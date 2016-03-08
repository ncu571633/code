/*
Given a linked list, determine if it has a cycle in it.
*/

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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode *a = head;
        ListNode *b = head->next;
        while(a&&b)
        {
            a=a->next;
            b=b->next;
            if(b)
                b=b->next;
            if(a==b)
                return true;
        }
        return false;
    }
};