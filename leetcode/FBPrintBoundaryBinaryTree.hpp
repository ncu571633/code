      1
   /    \
  2      3
 /  \   /  \
4    5 6    7
    /   \     \
   8     9     10

Answer will be : 1, 2, 4, 8, 9, 10, 7, 3

traverse(BinaryTree *root)
{
  if (!root) return;
  cout << p->data << " ";
  if (root->left ) traverseL(root->left ); //special function for outer left
  if (root->right) traverseR(root->right); //special function for outer right
}

traverseL(BinaryTree *p)
{
  cout << p->data << " ";
  if (root->left ) traverseL(root->left ); //still in outer left
  if (root->right) traverseC(root->right); 
}

traverseR(BinaryTree *p)
{
  if (root->left ) traverseC(root->left );
  if (root->right) traverseR(root->right); //still in outer right
  cout << p->data << " ";
}

traverseC(BinaryTree *p)
{
  if (!root->left && !root->right) //bottom reached
    cout << p->data << " ";
  else
  {
    if (root->left ) traverseC(root->left );
    if (root->right) traverseC(root->right);
  }
}
