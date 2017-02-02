Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


    TreeNode* sortedListToBST(ListNode* &head, int start, int end) {
        if(start > end)
            return nullptr;
        
        int mid = start + (end-start)/2;
        TreeNode* left = sortedListToBST(head, start, mid-1);
        TreeNode* root = new TreeNode(head->val);
        head=head->next;
        TreeNode* right = sortedListToBST(head, mid+1, end);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* t = head;
        int i=0;
        while(t) {
            t=t->next;
            i++;
        }
        return sortedListToBST(head, 0, i-1);
    }
};
