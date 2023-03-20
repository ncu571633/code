Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
    int count;
    int val;
public:
    Solution() {
        count = 0;
    }
    void help(TreeNode* root, int k) {
        if(!root)
            return ;
        kthSmallest(root->left, k);
        count++;
        if(count == k)
            val = root->val;
        kthSmallest(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        help(root, k);
        return val;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestDFS(root, k);
    }
    int kthSmallestDFS(TreeNode* root, int& k) {
        if(!root)
            return -1;
        int val = kthSmallestDFS(root->left, k);
        if(k==0)
            return val;
        k--;
        if(k==0)
            return root->val;
        return kthSmallestDFS(root->right, k);
    }   
};
