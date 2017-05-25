BST LCA with deepest leaf


TreeNode* dfs(TreeNode * root, int & depth){
    if(!root){
        depth = 0;
        return NULL;
    }
   
    int ldepth, rdepth;
    TreeNode * left = dfs(root->left, ldepth);
    TreeNode * right = dfs(root->right, rdepth);
    depth = 1 + max(ldepth, rdepth);
   
    if(ldepth == rdepth) return root;
    else if(ldepth < rdepth) return right;
    else return right;
}

int commonAncestor(TreeNode * root){
    int depth;
    TreeNode* LCA = dfs(root, depth);
    cout << "Tree depth:" << depth << endl;
    return LCA->val;
}. 


'Time complexity: O(n), space complexity: O(n)--hashmap has all the node'
public TreeNode findLCAIterative(TreeNode root) {
	if (root == null) {
		return null;
	}
    HashMap<TreeNode, TreeNode> childToParent = new HashMap<>();
    Queue<TreeNode> level = new LinkedList<>();
    TreeNode left = null;
    TreeNode right = null;
    level.offer(root);
    while (!level.isEmpty()) {
        int size = level.size();
        for (int i = 0; i < size; i++) {
            TreeNode node = level.poll();
            if (i == 0) {
                left = node;
            }
            if (i == size - 1) {
                right = node;
            }
            if (node.left != null) {
                level.offer(node.left);
                childToParent.put(node.left, node);
            }
            if (node.right != null) {
                level.offer(node.right);
                childToParent.put(node.right, node);
            }
        }
    }

    while (left != right) {
        left = childToParent.get(left);
        right = childToParent.get(right);
    }
    return left;
}
