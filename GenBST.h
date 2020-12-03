/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/
 #ifndef GENBST_H_
 #define GENBST_H_

 #include "TreeNode.h"


template <class x>
class GenBST
{
public:
  GenBST()
  {
    root = nullptr;
  }
  ~GenBST()
  {
    DeleteSubTree(root);
  }

  void InsertNode(x value)
  {
    TreeNode<x> *node = new TreeNode<x>(value);

    if(IsEmpty())
    {
      root = node;
    }
    else // not an empty tree, find insertion point
    {
      TreeNode<x> *current = root;
      TreeNode<x> *parent = nullptr;

      while(true)
      {
        //iterate to find insertion point
        parent = current;
        if(value < current -> key)
        {
          current = current -> left;

          if(current == nullptr)
          {
            //found location
            parent -> left = node;
            break;
          }
        }
        else
        {
          current = current -> right;

          if(current == nullptr)
          {
            parent -> right = node;
            break;
          }
        }
      }
    }
  }
  TreeNode<x>* ReturnPointerToNode(x value)
  {
    if(IsEmpty())
    {
      return nullptr;
    }

    TreeNode<x> *current = root;
    //tree is not empty, lets go looking for the node

    while(current != nullptr)
    {
      if(current ->  key == value)
      {
        break;
      }

      if(value < current -> key)
      {
        current = current -> left;
      }
      else
      {
        current = current -> right;
      }
    }//END while(current != nullptr || current -> key != value)

    return current;
  }
  bool IfSearchNode(x value)
  {
    if(IsEmpty())
    {
      return false;
    }
    else
    {
      //tree is not empty, lets go looking for the node
      TreeNode<x> *current = root;
      while(current -> key != value)
      {
        if(value < current -> key)
        {
          current = current -> left;
        }
        else
        {
          current = current -> right;
        }
        if(current == nullptr)
        {
          return false;
        }
      }
    }
    return true;
  }
  bool DeleteNode(x value)
  {
    if(IsEmpty()) // root is null
    {
      return false;
    }
    //invoke search to determine if it exists in the tree or not

    TreeNode<x>* parent  = nullptr;
    TreeNode<x>* current = root;
    bool isLeftNode   = true;

    //finding node
    while(current -> key != value)
    {
      parent = current;

      if(value < current -> key)
      {
        isLeftNode = true;
        current = current -> left;
      }
      else
      {
        isLeftNode = false;
        current = current -> right;
      }

      if(current == nullptr)
      {
        return false;
      }
    } // END while(current -> key != value)

    //at this point, we jave found our key, now we need to delete out InOrder

    //case: node to be deleted does not have children aka a leafnode
    if(current -> left == nullptr && current -> right == nullptr)
    {
      if(current == root) //root is only node in tree
      {
        root = nullptr;
      }
      else if(isLeftNode) //left child
      {
        parent -> left = nullptr;
      }
      else //right child
      {
        parent -> right = nullptr;
      }
    }//END if(current -> left == nullptr && current -> right == nullptr)
    //case: node to be deleted has one child, determin of decendent is left or right
    else if(current -> right == nullptr)//does not have right child, must be left
    {
        if(current == root)//root
        {
          root = current -> left;
        }
        else if(isLeftNode)  //left child
        {
          parent -> left = current -> left;
        }
        else //right child
        {
          parent -> right = current -> left;
        }
    }// END else if(current -> right == nullptr)
    else if(current -> left == nullptr)//does not have left child, must be right
    {
        if(current == root)//root
        {
          root = current -> right;
        }
        else if(isLeftNode)  //left child
        {
          parent -> left = current -> right;
        }
        else //right child
        {
          parent -> right = current -> right;
        }
    }//END else if(current -> left == nullptr)
    //case: node has 2 children
    else
    {
      //find successor
      TreeNode<x>* successor = GetSuccessor(current);//current is node to be deleteNode

      if(current == root)
      {
        root = successor;
      }
      else if(isLeftNode)
      {
        parent -> left = successor;
      }
      else
      {
        parent -> right = successor;
      }
      successor -> left = current -> left;

      return true;
    }

}

  TreeNode<x>* GetSuccessor(TreeNode<x> *d)//helper function for delete.  d is node to delete
  {
     TreeNode<x>* sp = d;
     TreeNode<x>* successor = d;
     TreeNode<x>* current = d -> right;

     while(current != nullptr)
     {
       sp = successor;
       successor = current;
       current = current -> left;
     }

     if(successor != d -> right)
     {
       sp -> left = successor -> right;
       successor -> right = d -> right;
     }

     return successor;

  }
  bool IsEmpty()
  {
    if(root == nullptr)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  x  GetMax()
  {
    if(root = nullptr)
    {
      throw "Tree Empty: No Max Value";
    }

    TreeNode<x> *temp = root;
    while(temp -> right != nullptr)
    {
      temp = temp -> right;
    }

    return temp -> key;
  }
  x  GetMin()
  {
    if(IsEmpty())
    {
      throw "Tree Empty: No Minimum Value";
    }

    TreeNode<x> *temp = root;

    while(temp -> left != nullptr)
    {
      temp = temp -> left;
    }

    return temp -> key;
  }


  void InOrder()
  {
    InOrderHelper(root);
  }
  void PostOrder()
  {
    PostOrderHelper(root);
  }
  void PreOrder()
  {
    PreOrderHelper(root);
  }


  void SerializeGenBST(ostream& oFile)
  {
    SerializeGenBSTHelper(oFile, root);
  }
  void SerializeGenBSTHelper(ostream& oFile, TreeNode<x>* parentNode)
  {
    if(parentNode == nullptr)
    {
      return;
    }

    oFile << parentNode -> key;
    SerializeGenBSTHelper(oFile, parentNode -> left);
    SerializeGenBSTHelper(oFile, parentNode -> right);
  }

protected:
  //traversals
    void InOrderHelper(TreeNode<x>* n)
    {
      if(n != nullptr)
      {
        InOrderHelper(n -> left);
        cout << n -> key << endl;
        InOrderHelper(n -> right);
      }
    }
    void PostOrderHelper(TreeNode<x>* n)
    {
      if(n != nullptr)
      {
        PostOrderHelper(n -> left);
        PostOrderHelper(n -> right);
        cout << n -> key << endl;
      }
    }
    void PreOrderHelper(TreeNode<x>* n)
    {
      if(n != nullptr)
      {
        cout << n -> key << endl;
        PreOrderHelper(n -> left);
        PreOrderHelper(n -> right);
      }
    }

    void DeleteSubTree(TreeNode<x>* n)
    {
      if(n == nullptr)
      {
        return;
      }

      DeleteSubTree(n -> left);
      DeleteSubTree(n -> right);
      delete n;
      n == nullptr;
    }


  TreeNode<x> *root;
};

 #endif // GENBST_H_
