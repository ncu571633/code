 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* s = new ListNode(0);
        s -> next = head;
        ListNode*l1 = s, *l2 = head;
        while(l2) {
            while(l2->next && l1->next->val == l2->next->val) {
                l2=l2->next;
            }
            if(l2 != l1->next) {
                l1->next = l2->next;
            } else {
                l1 = l2;
            }
            l2 = l2->next;
        }
        return s->next;
    }
};
