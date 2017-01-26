/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ... 
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* h2 = head->next;
        ListNode* t1 = head, *t2 = h2, *t3 = head;
        while(t1 && t2) {
            t1->next = t2->next;
            t3 = t1;
            t1 = t1->next;
            if(t1) {
                t3 = t1;
                t2->next = t1->next;
                t2 = t1->next;
                t1->next = nullptr;
            }
        }
        t3->next = h2;
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        
        ListNode*l1=new ListNode(0), *l2=new ListNode(0);
        ListNode* t=head, *head2=head->next;
        bool turn = true;
        while(t) {
            if(turn) {
                l1->next = t;
                l1 = l1->next;
            }
            else {
                l2->next = t;
                l2 = l2->next;
            }
            t = t->next;
            turn = (1-turn);
        }
        l1->next = head2;
        l2->next = nullptr;
        return head;
    }
};

