 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return head;
        for(RandomListNode* it=head; it; it=it->next->next) {
            RandomListNode* t = new RandomListNode(it->label);
            t->next = it->next;
            it->next = t;
        }
        for(RandomListNode* it=head; it; it=it->next->next) {
            if(it->random) {
                it->next->random = it->random->next;
            }
        }
        RandomListNode* ret = head->next;
        for(RandomListNode* it=head; it; ) {
            RandomListNode* t = it->next;
            if(t) {
                it->next = t->next;
            }
            it = t;
        }
        return ret;
    }
};
