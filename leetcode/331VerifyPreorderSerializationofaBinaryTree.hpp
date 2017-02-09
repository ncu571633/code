One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false



class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false;
        istringstream in(preorder);
        vector<string> v;
        string val;
        while (getline(in, val, ',')) v.push_back(val);
        if(v[0]==string("#") && v.size()>1)
            return false;
        int diff = 1;   // diff = outdegree – indegree
        // non empty node: 2 out, 1 in
        // empty node: 0 out, 1 in
        for(int i=0; i<v.size(); i++) {
            diff--;
            if(diff<0)
                return false;
            if(v[i]!=string("#"))
                diff+=2;
        }
        return (diff==0);
    }
};
