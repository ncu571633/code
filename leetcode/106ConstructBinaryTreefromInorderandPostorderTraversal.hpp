Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2) {
        if(l1>r1 || l2>r2)
            return nullptr;
        
        TreeNode* r = new TreeNode(postorder[r2]);
        int i = l1;
        for(; i<=r1; i++) {
            if(inorder[i] == postorder[r2])
                break;
        }
        r->left = buildTree(inorder, l1, i-1, postorder, l2, l2+i-l1-1);
        r->right = buildTree(inorder, i+1, r1, postorder, l2+i-l1, r2-1);
        return r;
    }
};
