/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode *findNext(TreeLinkNode *node)
    {
        if(!node)
            return nullptr;
            
        TreeLinkNode *p = node;
        while(p)
        {
            if(p->left)
                return p->left;
            if(p->right)
                return p->right;
            p = p->next;
        }
        return nullptr;
    }
    
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        if(root->left)
        {
            if(root->right)
                root->left->next = root->right;
            else 
                root->left->next = findNext(root->next);
        }
        if(root->right)
            root->right->next = findNext(root->next);
        connect(root->right);
        connect(root->left);
    }
};