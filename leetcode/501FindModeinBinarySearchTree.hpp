Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count). 


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
    vector<int> v;
    int lastValue;
    int count;
    int max;
public:
    Solution() {
        lastValue = INT_MIN;
        count = 0;
        max = 0;
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return v;
    }
    void inorder(TreeNode*root) {
        if(!root)
            return ;
        inorder(root->left);
        if(lastValue != root->val)
            count = 1, lastValue = root->val;
        else
            count++;
        if(count == max) {
            v.push_back(root->val);
        }
        if(count > max) {
            v.clear();
            v.push_back(root->val);
            max = count;
        }
        inorder(root->right);
    }
};
