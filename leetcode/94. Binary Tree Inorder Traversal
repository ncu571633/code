Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3

return [1,3,2]. 


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
    void inorderTraversal(TreeNode* root, vector<int> &v) {
        if(!root)
            return ;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);      
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorderTraversal(root, v);
        return v;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            while(s.top()) {
                s.push(s.top()->left);
            }
            s.pop();
            if(!s.empty()) {
                TreeNode *t = s.top();
                v.push_back(t->val);
                s.pop();
                s.push(t->right);
            }
        }

        return v;
    }
};
