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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        
        if (list1->val > list2->val)
            return mergeTwoLists(list2, list1);
        
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
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
