an AVL tree is a self-balancing binary search tree.
BalanceFactor(N) := Height(RightSubtree(N)) –Height(LeftSubtree(N))

4 cases: mirrored version
1. rotate right, rotate left

a balance factor of -2.
a
 \
  b
   \
    c


  b
a   c



2. Rotate left Right, rotate right left

a
 \
  c


a
 \
  c
 /
b

Right rotaion on the right subtree
a
 \
  b
   \
    c
Left Rotation
  b
 / \
a   c


