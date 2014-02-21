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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return head;
        ListNode *p1 = head, *p2 = head;
        int i = 1;
        while(p1->next!=NULL)
        {
            i++, p1=p1->next;
        }
        p1=head;
        k = k%i;
        i=0;
        while(i<k && p1!=NULL)
        {
            p1=p1->next;
            i++;
        }
        if(p1==NULL)
           return head;
        while(p1->next!=NULL)
        {
            p1=p1->next, p2=p2->next;
        }
        p1->next = head;
        head = p2->next;
        p2->next = NULL;
        return head;
    }
};
