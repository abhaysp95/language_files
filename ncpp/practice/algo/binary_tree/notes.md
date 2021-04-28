# Binary Tree

* Binary tree can have at max only 2 children(a node can have only children too)

## Properties

* maximum nodes at level _L_ = `2^L`(we'll also consider root as level 0)
* maximum nodes in a tree of height _H_ = `2^H - 1` (this subtraction of 1 is because at level 0(height 1), there is just root)
* for _n_ nodes, minimum possible height or minimum numbers of levels = `ln(N+1)`
* minimum number of levels with binary tree of _L_ leaves = `ln(N+1) + 1`

## Traversel

### Pre-Order

* You vist a node(and write the value of it), then you visit the `left-subtree` of that node and come back to that node again, and then you visit its `right-subtree`.
* In simple way, this traversal is shown as: _(root, left, right)_.

### In-Order

* You visit the `left-subtree` of the node first and then you visit the node(write the value of node itself), and then you visit that node's `right-subtree`.
* In simple way, this traversal is shown as: _(left, root, right)_.

### Post-Order

* You first visit the `left-subtree` of the node and then you visit the `right-subtree` of the node and then you visit the node itself(write the value of the node itself).
* In simple way, this traversal is shown as: _(left, right, root)_.

## Tree building

### From Pre-Order and In-Order

`Note: I will be saying Pre-Order as PR and In-order as IO`

* pick element from PR and create the index with it
* incremenet PR index
* search the picked element position in IO
* call to build left-subtree from IO's 0 to position - 1
* call to build right-subtree from IO's position + 1 to n
* return the node

## Height for binary tree:

### when height is node's property:

* the _height_ of a node is the number of edges on the longest path from the node to a leaf.

### when height is tree's property:

* the _height_ of  a tree would be the height of root node or equivalently the depth of the deepest node.

## Depth for binary tree:

### when depth is node's property:

* the _depth_ of a node is the number of edges from the node to the tree's root node.

### diameter of width of tree:

* the _diameter_(or _width_) of a tree is the number of nodes on the longest path between any two leaf nodes.

## Sum Replacement

* Replace the value of each node with sum of all subtree nodes and itself

## Balanced Height Binary Tree

* For each node, the difference between the heights of the left subtree and right subtree should be <= 1
