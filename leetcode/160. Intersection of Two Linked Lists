Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B, int lenDiff) {
        ListNode*t1=A;
        for(int i=0; i<lenDiff; i++)
            t1=t1->next;
        for(ListNode*t2=B; t1&&t2&&t1!=t2; t1=t1->next, t2=t2->next);
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1=0, size2 = 0;
        for(ListNode*t=headA; t; t=t->next)
            size1++;
        for(ListNode*t=headB; t; t=t->next)
            size2++;        
        if(size1>size2)
           return getIntersectionNode(headA, headB, size1-size2);
        else
           return getIntersectionNode(headB, headA, size2-size1); 
    }
};
