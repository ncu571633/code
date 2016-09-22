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
        ListNode* newNode = new ListNode(0);
        newNode->next = head;
        head = newNode;
        if(!(head->next))
            return nullptr;
        ListNode*l1=head, *l2=head;
        for(int i=1; i<=n; i++)
            l2=l2->next;
        for(; l2->next; l2=l2->next)
            l1=l1->next;
        l1->next = l1->next->next;
        return head->next;
    }
};
