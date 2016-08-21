Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3



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
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if(!l && !r)
            return true;
        if(!l&&r || l&&!r || l->val!=r->val)
            return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};
