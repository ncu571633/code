Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t1 = new ListNode(0);
        t1->next = head;
        head = t1;
        for(int i=0; i<n; i++)
            t1=t1->next;
        ListNode* t2=head;
        while(t1->next) {
            t1=t1->next;
            t2=t2->next;
        }
        t2->next = t2->next->next;
        return head->next;
    }
};
