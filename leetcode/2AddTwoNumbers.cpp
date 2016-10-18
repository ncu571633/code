You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* h = l;
        int addition = 0;
        while(l1 && l2) {
            l->next = new ListNode(l1->val + l2->val + addition);
            l=l->next;
            addition = (l->val)/10;
            l->val = (l->val)%10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            l->next = new ListNode(l1->val + addition);
            l=l->next;
            addition = (l->val)/10;
            l->val = (l->val)%10;
            l1 = l1->next;
        }
        while(l2) {
            l->next = new ListNode(l2->val + addition);
            l=l->next;
            addition = (l->val)/10;
            l->val = (l->val)%10;
            l2 = l2->next;
        }
        if(addition) {
            l->next = new ListNode(addition);
        }
        return h->next;
    }
};
