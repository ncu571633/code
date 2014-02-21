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
