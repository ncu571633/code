 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l = new ListNode(0);
        ListNode* h = l;
        while(true) {
            int min = INT_MAX;
            int index = -1;
            for(int i=0; i<lists.size(); i++) {
                if(lists[i] && lists[i]->val < min) {
                    min = lists[i]->val;
                    index = i;
                }
            }
            if(min == INT_MAX)
                break;
            l->next = new ListNode(lists[index]->val);
            l = l->next;
            lists[index]=lists[index]->next;
        }
        return h->next;
    }
};


class Solution {
public:
    struct cmp {
        bool operator() (ListNode* l1, ListNode*l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) q.push(lists[i]);
        }
        ListNode* h = new ListNode(0);
        ListNode* l = h;
        while(!q.empty()) {
            ListNode* t = q.top();
            q.pop();
            l->next = t;
            l = t;
            if(t->next)
                q.push(t->next);
            t->next = nullptr;
        }
        return h->next;
    }
};
