Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if(l1 > r1 || l2 > r2)
            return nullptr;
        TreeNode* t = new TreeNode(preorder[l1]);
        int i = l2;
        for(; i<=r2; i++)
        {
            if(preorder[l1] == inorder[i])
                break;
        }
        t->left = buildTree(preorder, l1+1, l1+i-l2, inorder, l2, i-1);
        t->right = buildTree(preorder, l1+i-l2+1, r1, inorder, i+1, r2);
        return t;
    }
};
