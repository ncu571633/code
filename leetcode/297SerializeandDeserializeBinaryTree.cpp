Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself. 



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    vector<int> serialize(TreeNode* root) {
        vector<int> v;
        if(!root)
        {
            v.push_back(-INT_MAX);
            return v;
        }
        
        v.push_back(root->val);
        vector<int> v1 = serialize(root->left);
        vector<int> v2 = serialize(root->right);
        v.insert(v.end(), v1.begin(), v1.end());
        v.insert(v.end(), v2.begin(), v2.end());
        return v;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(vector<int> data, int& index) {
        if(data.size() <= index || data[index] == -INT_MAX)
            return nullptr;
        
        TreeNode* t = new TreeNode(data[index]);
        t->left = deserialize(data, ++index);
        t->right = deserialize(data, ++index);
        return t;
    }    
    
    TreeNode* deserialize(vector<int> data) {
        int i = 0;
        return deserialize(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
