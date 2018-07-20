Given a Binary Tree, find diameter of it.  The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

int height(Node* node)
{
    if(!node)
        return 0;
    return 1+max(height(node->left), height(node->right));
}

int diameter(Node* node)
{
   // Your code here
    if(!node)
       return 0;
    
    return max(height(node->left)+height(node->right)+1, 
        max(diameter(node->left), diameter(node->right)));   
}
