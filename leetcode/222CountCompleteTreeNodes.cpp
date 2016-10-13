Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int height1 = 0, height2 = 0;;
        TreeNode* t = root;
        while(t) {
            height1++;
            t = t->left;
        }
        t = root;
        while(t) {
            height2++;
            t=t->right;
        }
        if(height1==height2)
            return pow(2, height1)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
