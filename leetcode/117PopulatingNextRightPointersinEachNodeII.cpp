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

/*
 * Definition for binary tree with next pointer.
 */
 #include "stdio.h"
 struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

#if 0
class Solution {
public:
    TreeLinkNode * findNext(TreeLinkNode *first) {
        for(TreeLinkNode *t=first; t; t=t->next) {
            if(t->left)
                return t->left;
            if(t->right)
                return t->right;
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
#endif

TreeLinkNode * findNext(TreeLinkNode *root) {
    for(TreeLinkNode *t=root->next; t; t=t->next) {
        if(t->left)
            return t->left;
        if(t->right)
            return t->right;
    }
    return nullptr;
}
void connect(TreeLinkNode *root) {
    if(!root)
        return;
    TreeLinkNode *nexti = root;
    while(nexti) {
        TreeLinkNode *nextj = nexti;
        while(nextj) {
            if(nextj->left) {
                if(nextj->right) {
                    nextj->left->next = nextj->right;
                } else {
                    nextj->left->next = findNext(nextj);
                }
            }
            if(nextj->right) {
                nextj->right->next = findNext(nextj); 
            }
            nextj = nextj->next;
        }

        if(nexti->left)
            nexti=nexti->left;
        else if(nexti->right)
            nexti=nexti->right;
        else nexti = findNext(nexti);
    }
}

int main() 
{
    TreeLinkNode t(0);
    connect(&t);
}
