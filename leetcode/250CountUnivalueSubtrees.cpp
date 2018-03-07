Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int res = isUnivalTree(root);
        res += countUnivalSubtrees(root->right);
        res += countUnivalSubtrees(root->left);
        return res;
    }
    bool isUnivalTree(TreeNode* r, int v)
    {
        if (r == nullptr)
            return true;
        return (r->val == v) && isUnivalTree(r->left, v) && isUnivalTree(r->right, v)
    }
}

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int ret = 0; 
        isUnivalTree(root, -1, ret);
        return ret;
    }
    bool isUnivalTree(TreeNode* r, int v, int& ret)
    {
        if (r == nullptr)
            return true;
        if (!isUnivalTree(r->left, root->val, ret) || !isUnivalTree(r->right, root->val, ret))
            return false;
        ret++;
        return root->val = v;
    }
}
