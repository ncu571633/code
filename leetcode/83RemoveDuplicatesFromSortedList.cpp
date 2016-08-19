 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 


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
        if(!head)
            return head;
        for(ListNode* t1=head, *t2=head->next; t2; ) {
            if(t2->val == t1->val) {
                t1->next = t2->next;
            } else {
                t1 = t2;
            }
            t2 = t1->next;
        }
        return head;
    }
};
