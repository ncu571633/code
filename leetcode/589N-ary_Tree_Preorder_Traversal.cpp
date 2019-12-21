Given an n-ary tree, return the preorder traversal of its nodes' values.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if(!root)
            return ret;

        ret.push_back(root->val);
        for(int i=0; i<root->children.size(); i++)
        {
            vector<int> t = preorder(root->children[i]);
            ret.insert(ret.end(), t.begin(), t.end());
        }
        return ret;
    }
};
