Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<TreeNode *> v;
    int index;
public:
    BSTIterator(TreeNode *root) {
        dfs(root);
        index = 0;
    }

    void dfs(TreeNode* root) {
        if(!root)
            return ;
        dfs(root->left);
        v.push_back(root);
        dfs(root->right);
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index<v.size())
            return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        return v[index++]->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
