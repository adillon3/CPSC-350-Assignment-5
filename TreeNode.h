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
    TreeNode()
    {
      left  = nullptr;
      right = nullptr;
    }

    TreeNode(x newKey)
    {
      left  = nullptr;
      right = nullptr;
      key   = newKey;
    }

    TreeNode& operator=(const TreeNode &other)
    {
      if(this != &other)
      {
        this.left = other.left;
        this.right = other.right;
        this.key = other.key;
      }

      return *this;
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
