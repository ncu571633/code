/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

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
    bool isDescendant(TreeNode* a, TreeNode* p)
    {
        if(!a)
            return false;
        if(a==p)
            return true;
        return isDescendant(a->left, p) || isDescendant(a->right, p);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
            
        bool a = isDescendant(root->left, q), c = isDescendant(root->left, p);
        // q left, p left
        if(a && c)
            return lowestCommonAncestor(root->left, p, q);
        
        bool b = isDescendant(root->right, q), 
        d = isDescendant(root->right, p);
        // q right, p right
        if(b && d)
            return lowestCommonAncestor(root->right, p, q);       
        
        // q left, p right; q right, p left
        if(a&&d || b&&c)
            return root;
        
        if((root==p)&&(a||b) || (root==q)&&(c||d))
            return root;
            
        return nullptr;
    }
};