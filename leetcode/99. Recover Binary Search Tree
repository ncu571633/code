 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 

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
private:
    TreeNode* n1;
    TreeNode* n2;
    TreeNode* last;
public:
    Solution() {
        n1 = nullptr;
        n2 = nullptr;
        last = nullptr;
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        if(n1 && n2)
            swap(n1->val, n2->val);
    }
    void dfs(TreeNode* r)
    {
        if(!r)
            return;
        dfs(r->left);
        if(last && last->val > r->val) {
            if(!n1)
                n1 = last;
            if(n1)
                n2 = r;
        }
        last = r;
        dfs(r->right);
    }
};
