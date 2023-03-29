Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

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
    TreeNode* last;
public:
    void flatten(TreeNode* root) {
        if (!root)
            return ;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* last = root;
        while(last->right)
        {
            last = last->right;
        }
        last->right = temp;       
    }
};
