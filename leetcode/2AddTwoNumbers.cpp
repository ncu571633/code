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

class Solution {
public:
    int getListSize(ListNode *l)
    {
        int n = 0;
        for(ListNode* p=l; p!=nullptr; p=p->next)
            n ++;
        return n;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1 = getListSize(l1);
        int s2 = getListSize(l2);
        
        if (s1 < s2)
            return addTwoNumbers(l2, l1);
        
        // assume l1 is longer than or equal to l2
        bool carry = false;
        ListNode* p = nullptr;
        ListNode* p1 = l1;
        for(ListNode *p2 = l2; p2!=nullptr; p1 = p1->next, p2 = p2 -> next)
        {
            p = p1;
            p1->val = p1->val + p2->val + carry;
            if (p1->val >= 10)
            {
                p1->val -= 10;
                carry = true;
            }
            else
                carry = false;
        }
        
        for (; p1!=nullptr && carry; p1 = p1->next)
        {
            p = p1;
            p1->val += carry;
            if (p1->val >= 10)
            {
                p1->val -= 10;
                carry = true;
            }
            else
                carry = false;            
        }
        
        if (carry)
        {
            p->next = new ListNode(1);
        }            
        
        return l1;
    }
};
