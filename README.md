# Wordrange

README for Wordrange
Vince Moreno, 19 May 2024



Description
The Wordrange folder contains the "wordrange" executable which allows a user
input a file of words or numbers. The program stores and sorts the values in
the file in an AVL tree. The user can then find how many values are between
two given values in the AVL tree (lexigrahically if strings). The Tests folder 
contains input and output files to test the code on.



Files
Code Files: Makefile, wordrange.cpp, avl.cpp
Input/Output Files: simple-input.txt, simple-output.txt
Extra files: README

The Tests folder contains input and output .txt files.
Input Files: allwords-basic.txt, simple-input.txt, allwords-more-range.txt
Output Files: allwords-basic-output.txt, simple-output.txt, allwords-more-range-output.txt



Usage
In main folder:
  1. Run "make", to get executable "wordrange"
  2. Run "./wordrange <INPUT FILE> <OUTPUT FILE>"



Input/Output
Each line of the input file will be of the following two forms:
i <STRING>
or
r <STRING1> <STRING2>

The first line means to insert a string into the AVL tree
The second line above means: count the number of strings 
(currently stored) that are lexicographically between STRING1 and STRING2.
The count is printed to the <OUTPUT FILE> provided as an argument



AVL Trees (avl.cpp)
The cpp file wordrange.cpp uses the AVL tree implemented by avl.h and avl.cpp
to efficienty store and traverse through the heap of words given by the input
file. An AVL tree is more efficient than a normal Binary Search tree in that it
keeps the left and right subtrees balanced. Each node in the tree contains a 
balance factor which is equal to the height of the left node minus the height
of the right node. If the balance factor of a node is greater than 1 or less
than -1, the tree will reorder the nodes to balance itself out. It does the
process of balancing through four different types of rotations: Right, Left,
RightLeft, LeftRight. Each rotation is used for a specific case depending on the
nodes' balance factors. Each time a node is inserted, the tree recursively balances
the tree nodes which allows the time complexity to traverse the tree to remain at
O(log n). This allows for fast traversing when doing the range query operations --
it allows for over 1 million range operations in under 20 seconds. The function 
countInRange() gives the answer to the range queries in O(log n) time through 
recursion. Each node also contains an int value that says how many child nodes 
it stores. Using this value allows the function to make less recursive calls.

Sources I used to understand AVL trees
https://www.youtube.com/watch?v=zP2xbKerIds&ab_channel=MaanethDeSilva
https://www.youtube.com/watch?v=jDM6_TnYIqE&ab_channel=AbdulBari
Lecture recordings from CSE101 in University of California, Santa Cruz
