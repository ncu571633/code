Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;

        if(head->val==val)
            return removeElements(head->next, val);
        else {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;

        ListNode* t = new ListNode(0);
        t->next = head;
        head = t;
        while(t->next) {
            if(t->next->val == val) {
                t->next = t->next->next;
            } else {
                t = t->next;
            }
        }
        return head->next;
    }
};
