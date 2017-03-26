Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.

Example:
Given binary tree

          1
         / \
        2   3
       / \     
      4   5    

Returns [4, 5, 3], [2], [1].

Explanation:

1. Remove the leaves [4, 5, 3] from the tree

          1
         / 
        2          

2. Remove the leaf [2] from the tree

          1          

3. Remove the leaf [1] from the tree

          []         

Returns [4, 5, 3], [2], [1].

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> m;
        help(root, m);
        return m;
    }
    int help(TreeNode* root, vector<vector<int>>& m) {
        if(!root)
            return -1;
        int depth = 1+max(help(root->left, m), help(root->right, m));
        if(m.size()<depth) {
            vector<int> v;
            m.push_back(v);        
        } 
        m.back().push_back(root->val);
        return depth;
    }
}
