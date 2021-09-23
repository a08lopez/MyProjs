// Specification file for the IntBinaryTree class
 #ifndef INTBINARYTREE_H
  #define INTBINARYTREE_H
#include <iostream>
#include <stdlib.h>
/*
 * Programmer: Arturo Lopez
 * Date: 5/25/2019
 * Assignment 8
 *
 */

  class IntBinaryTree
  {
     private:
     struct TreeNode
      {
        int value;       // The value in the node
        TreeNode *left;   // Pointer to left child node
        TreeNode *right;  // Pointer to right child node
      };  TreeNode *root;  // Pointer to the root node
        // Private member functions
          void insert(TreeNode *&, TreeNode *&);
          void destroySubTree(TreeNode *);
          void displayInOrder(TreeNode *) const;
          int leafCounter(TreeNode *);
          int treeHeight(TreeNode *);
          int treeWidth(TreeNode *);
          int getWidth(TreeNode* , int);
          public:
           // Constructor
          IntBinaryTree()
          {
            root = nullptr;
          }
          // Destructor
          ~IntBinaryTree()
           {
            destroySubTree(root);
           } // Binary tree operations
          void nodeInsert();

          void displayInOrder() const
          {
            std::cout << "Nodes displayed in order " << std::endl;
            displayInOrder(root);
          }

          void countLeafs()
          {
            std::cout << "The number of leaf nodes is " << std:: endl;
            std::cout << leafCounter(root) << std::endl;
          }

          void displayHeight()
          {
            std::cout << "The height of the tree is " << std:: endl;
            std::cout << treeHeight(root) << std::endl;
          }
          void displayWidth()
          {
            std::cout << "The width of the tree is  " << std:: endl;
            std::cout << treeWidth(root) << std::endl;
          }
          void closeProgram();
};
#endif
