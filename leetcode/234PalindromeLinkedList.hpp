Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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
        if(!head || head->next == nullptr)
            return head;
        ListNode* p = head->next;
        head->next = nullptr;
        while(p) {
            ListNode* t = p->next;
            p->next = head;
            head = p;
            p = t;
        }
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* slow=head, *fast=head;
        while(fast->next&&fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverseList(slow->next);
        while(slow) {
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};
