
#include "IntBinaryTree.h"

/*
 * Programmer: Arturo Lopez
 * Date: 5/25/2019
 * Assignment 8
 *
 */
/*
/***************************************************
 * Name: IntBinaryTree
 * Arguments: *nodePtr
 * return: nothing
 * Helper function destroySubTree is called by the destructor. It
 * deletes all nodes in the tree.
  //***************************************************/
    void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
    {
      if(nodePtr)
      {
       if(nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
         delete nodePtr;
         }
     }

     /***************************************************
      * Name: insert
      * Arguments: *&nodePtr and *&newNode
      * return: nothing
      * Function insert will insert the element into
      * the left or right subtree.
       //***************************************************/
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
  if (nodePtr == nullptr)
      nodePtr = newNode; // Insert the node.
  else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode); // Search the left branch.
  else
      insert(nodePtr->right, newNode); // Search the right branch.
}

/***************************************************
 * Name: nodeInsert
 * Arguments: nothing
 * return: nothing
 * Function nodeInsert will help the function insert
 * in asking for the element and assigning the element
 * to the newNode and calling insert.
  //***************************************************/
  void IntBinaryTree::nodeInsert()
  {
    int num;
    std::cout << "Please enter a number to place into stack." << std::endl;
    std::cin >> num;
     TreeNode *newNode = nullptr;  // Pointer to a new node.
    // Create a new node and store num in it.
     newNode = new TreeNode;
     newNode->value = num;
     newNode->left = newNode->right = nullptr;
    // Insert the node.
     insert(root, newNode);
  }
  /***************************************************
   * Name: displayInOrder
   * Arguments: *nodePtr
   * return: nothing
   *The displayInOrder member function displays the values
   * in the subtree pointed to by nodePtr, via inorder traversal.
    //*************************************************************/
    void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
    {
      if (nodePtr)
        {
          displayInOrder(nodePtr->left);
          std::cout << nodePtr->value << std::endl;
          displayInOrder(nodePtr->right);
        }
    }

    /***************************************************
     * Name: leafCounter
     * Arguments: *nodePtr
     * return: number of leafs
     * The function will count the number of leafs
     * in both the left subtree and the right subtree
     * and total them up.
      //*************************************************************/
    int IntBinaryTree::leafCounter(TreeNode *nodePtr)
    {
      int leftCount;
      int rightCount;
      //will check if tree is empty
      if(nodePtr == nullptr)
      {
        return 0;
      }
      //will check if tree has one node and will return one leaf.
      if(nodePtr->left == nullptr && nodePtr->right == nullptr)
      {
        return 1;
      }
      else
      {
        leftCount = leafCounter(nodePtr->left);
        rightCount = leafCounter(nodePtr->right);
        return leftCount + rightCount;
      }
    }

    /***************************************************
     * Name: treeHeight
     * Arguments: *nodePtr
     * return: tree height
     * Function will count both the height of the left
     * and the right subtrees and return whichever one is higher.
      //*************************************************************/
    int IntBinaryTree::treeHeight(TreeNode *nodePtr)
    {
      //will check if tree is empty
      if(nodePtr == nullptr)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lHeight = treeHeight(nodePtr->left);
        int rHeight = treeHeight(nodePtr->right);

        /* use the larger one */
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
          return (rHeight + 1);
    }
    }

    /***************************************************
     * Name: treeWidth
     * Arguments: *nodePtr
     * return: tree width
     * Function will count the treeWidth by using both
     * helper functions treeHeight and getWidth.
      //*************************************************************/
    int IntBinaryTree::treeWidth(TreeNode *nodePtr)
    {
      int maxWidth = 0;
    int width;
    if(nodePtr == nullptr)
    {
        return 0;
    }
    int h = treeHeight(nodePtr);
    int i;

    /* Get width of each level and compare
        the width with maximum width so far */
    for(i = 1; i <= h; i++)
    {
        width = getWidth(nodePtr, i);
        if(width > maxWidth)
          maxWidth = width;
    }
    return maxWidth;
    }

    /***************************************************
     * Name: getWidth
     * Arguments: *nodePtr and level
     * return: tree width
     * Function will count the width of each branch in the
     * left subtree and right subtree.
      //*************************************************************/
    int IntBinaryTree::getWidth(TreeNode* nodePtr, int level)
    {

      //
      if(nodePtr == nullptr)
        return 0;

        if(level == 1)
          return 1;

        else
          return getWidth(nodePtr->left, level - 1) +
                getWidth(nodePtr->right, level - 1);
    }
    /***************************************************
     * Name: closeProgram
     * Arguments: none
     * return: nothing
     * Function will close the program.
      //*************************************************************/
void IntBinaryTree::closeProgram()
{
  exit(EXIT_FAILURE);
}
