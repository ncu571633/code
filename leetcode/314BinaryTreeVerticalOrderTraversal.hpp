Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its vertical order traversal as:

[
  [9],
  [3,15],
  [20],
  [7]
]

Given binary tree [3,9,20,4,5,2,7],

    _3_
   /   \
  9    20
 / \   / \
4   5 2   7

return its vertical order traversal as:

[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            vector<int, vector<int>> ret;
            return ret;
        }

        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.insert({0, root});
        while(!q.empty()) {
            pair<int, TreeNode*> p = q.top();
            q.pop();
            m[p.first].push_back(p.second->val);
            if(p.second->left)
                q.insert({p.first-1, p.second->left});
            if(p.second->right)
                q.insert({p.first+1, p.second->right});
        }
        return vector<int, vector<int>>(m.begin(), m.end());
    }
