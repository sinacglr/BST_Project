# BST_Project
## CSE225 Data Structures – FALL 2023
## PROJECT #1 (Due December 8, 2023, Friday at 23:59)
In this project, you will implement a special tree structure which satisfy following conditions:
- Each node will have a key value and frequency value (Frequency value represents search
frequency of the key value)
- It will be a binary search tree (BST), so
  + each node has at most two children (left child and right child)
  + left child has smaller key value than the node itself
  + right child has greater key value than the node itself
- Every parent node has greater frequency value than all of its children.
You will implement this in two different ways.
a) Offline version:
- Your program will construct this tree using a given input file that contains key values
and corresponding frequency values.
b) Online version:
- Your program will construct the tree using a given input file that contains key values
(like normal BST). At the beginning frequency values of each nodes will be 0.
- After constructing the tree, it will prompt the user to enter a number to search. When a
value is searched, frequency value of corresponding node will be increased by 1.
- The program will update the tree for each search, increasing the frequency of the node
and adjusting the node arrangement to satisfy the specified conditions.
- After each search your tree must perform necessary rotations to satisfy the conditions.
- After completing all necessary rotations it will print pre-order traversal of the tree.
