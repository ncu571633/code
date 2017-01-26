Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* t = h;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                t->next=l1;
                l1=l1->next;
            }else{
                t->next=l2;
                l2=l2->next;
            }
            t=t->next;
        }
        if(l1)
            t->next=l1;
        if(l2)
            t->next=l2;
        return h->next;
    }
};
