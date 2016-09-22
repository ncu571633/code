 Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]

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
    void binaryTreePaths(TreeNode* root, string s, vector<string>& v) {
        if(root->right==nullptr && root->left==nullptr)
            v.push_back(s);
        if(root->left)
            binaryTreePaths(root->left, s+string("->")+to_string(root->left->val), v);
        if(root->right)
            binaryTreePaths(root->right, s+string("->")+to_string(root->right->val), v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(!root)
            return v;
        binaryTreePaths(root, to_string(root->val), v);
        return v;
    }
};
