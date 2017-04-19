

The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.

start and end are both integers, they should be assigned in following rules:

    The root's start and end is given by build method.
    The left child of node A has start=A.left, end=(A.left + A.right) / 2.
    The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
    if start equals to end, there will be no children for this node.

Implement a build method with a given array, so that we can create a corresponding segment tree with every node value represent the corresponding interval max value in the array, return the root of this segment tree.
Clarification

Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:

    which of these intervals contain a given point
    which of these points are in a given interval

See wiki:
Segment Tree
Interval Tree
Example

Given [3,2,1,4]. The segment tree will be:

                 [0,  3] (max = 4)
                  /            \
        [0,  1] (max = 3)     [2, 3]  (max = 4)
        /        \               /             \
[0, 0](max = 3)  [1, 1](max = 2)[2, 2](max = 1) [3, 3] (max = 4)



/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        if (A.empty())
            return nullptr;
        return build(A, 0, A.size()-1);
    }
    SegmentTreeNode * build(vector<int>& A, int start, int end) {
        if(start>end)
            return nullptr;
        SegmentTreeNode* r = new SegmentTreeNode(start, end);
        if (start < end) {
            int mid = (start+mid)/2;
            r->left = build(A, start, mid);
            r->right = build(A, mid+1, end);
            r->max = max(r->left->max, r->right->max);
        } else {
            r->max = A[start];
        }
        return r;
    }
};
