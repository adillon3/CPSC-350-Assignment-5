/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

 #ifndef TREENODE_H_
 #define TREENODE_H_

 #include <iostream>
 using namespace std;

 #include <string>
 #include <fstream>

template <class x>
class TreeNode
{
  public:
    TreeNode(x newKey)
    {
      left  = nullptr;
      right = nullptr;
      key   = newKey;
    }
    ~TreeNode()
    {/*
      delete left;
      delete right;
      left  = nullptr;
      right = nullptr;*/
    }


    x key; //data as well as key
    TreeNode *left;
    TreeNode *right;
  private:

};

 #endif // TREENODE_H_
