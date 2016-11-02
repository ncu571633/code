Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> m;
        if(!root)
            return m;
        queue<TreeNode*> q;
        q.push(root);
        int order = 1;
        while(!q.empty()) {
            vector<int> v;
            int size = q.size();
            for(int i=0; i<size; i++) {
                v.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(order%2==0)
                reverse(v.begin(), v.end());
            order++;
            m.push_back(v);
        }
        return m;
    }
};
