/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be chang
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* a = head;
        ListNode* b = head->next;
        a->next = swapPairs(b->next);
        b->next = a;
        return b;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next==nullptr)
            return head;

        ListNode* t1=head, *t2=head->next;
        head=t2;
        while(t1 && t2) {
            ListNode* t = t2->next;
            t2->next = t1;
            if(t && t->next)
                t1->next = t->next;
            else
                t1->next = t;
            t1 = t;
            if(t) {
                t2=t->next;
            }
        }
        return head;
    }
};
