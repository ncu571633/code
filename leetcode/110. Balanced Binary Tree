Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 


class Solution {
public:
    int getHeight(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(getHeight(root->left)-getHeight(root->right))>1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
