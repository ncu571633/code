Reverse a singly linked list.


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
    ListNode* reverseList(ListNode* head) {
        if(!head || head->next == nullptr)
            return head;
        ListNode* t = head->next;
        while(t)
        {
            ListNode* a = t->next;
            t->next = head;
            head = t;
            t = a;
        }
        return head;
    }
};
