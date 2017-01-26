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
        if(!head || head->next==nullptr)
            return head;
        ListNode* p = head->next;
        ListNode* n = reverseList(head->next);
        head->next = nullptr;  
        p->next = head;  
        return n;        
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;

        ListNode* t = head->next;
        head->next = nullptr;
        while(t) {
            ListNode* n = t->next;
            t->next = head;
            head = t;
            t = n;
        }
        return head;
    }
};

