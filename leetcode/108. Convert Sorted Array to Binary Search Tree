Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


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
    TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
        if(i>j)
            return nullptr;
        int k = (i+j)/2;
        TreeNode* n = new TreeNode(nums[k]);
        n->left = sortedArrayToBST(nums, i, k-1);
        n->right = sortedArrayToBST(nums, k+1, j);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};
