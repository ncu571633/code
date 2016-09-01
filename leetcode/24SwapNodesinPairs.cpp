/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be chang
*/

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* a = head;
        ListNode* b = head->next;
        a->next = swapPairs(b->next);
        b->next = a;
        return b;
    }
};


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *l = new ListNode (0);
        l->next = head;
        ListNode *p1 = head, *p2 = head->next;
        head = NULL;
        while(p1!=NULL && p2!=NULL)
        {
            p1->next = p2->next;
            p2->next = p1;            
            l->next = p2;
            if(head==NULL)
               head = l;
            l = p1;
            p1=p1->next;
            if(p1!=NULL)
                p2= p1->next;
        }
        return head->next;
    }
};
