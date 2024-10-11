Spell-Checking system based on binary search trees, given a file containing all language words. User is prompted to enter the sentence to check its spelling. 
The words are then checked in the binary tree if it exists. If it does, it prints out correct. Else three suggestions are printed out based on these 3 things:

1. The word in the last node reached before decalaration that the word does not exist
2. Inorder predecessor of that node
3. Inorder successor of that node

Key features:
1. Utilized Binary Search Trees (BSTs) for efficient word storage and fast lookup, reducing time complexity to O(log n) for search and insertion operations.
2. Implemented file handling to load a dictionary from a text file and check a target text file for spelling errors.
3. Provided suggestions for misspelled words by traversing the tree and analyzing similar word structures.
4. Enhanced understanding of tree-based data structures and their application in real-world problems.
5. Successfully implemented a scalable system capable of handling large dictionaries and text files.
