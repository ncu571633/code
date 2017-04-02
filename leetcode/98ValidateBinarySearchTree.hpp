 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

    2
   / \
  1   3

Binary tree [2,1,3], return true.

Example 2:

    1
   / \
  2   3

Binary tree [1,2,3], return false. 

class Solution {
private:
    bool first;
    int lastVal;
public:
    Solution() {
        first = true;
        lastVal = INT_MIN;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(root->val <= lastVal && !first)
            return false;
        first = false, lastVal = root->val;
        return isValidBST(root->right);
    }
};


class Solution {
private:
    TreeNode* last;
public:
    Solution() {
        last = nullptr;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(last && root->val <= last->val)
            return false;
        last = root;
        return isValidBST(root->right);
    }
};
