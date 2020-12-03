/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/
 #include "StudentBST.h"

 void StudentBST :: SerializeStudentBST(ostream& oFile)
 {
   SerializeStudentBSTHelper(oFile, root);
 }
 void StudentBST :: SerializeStudentBSTHelper(ostream& oFile, TreeNode<Student>* parentNode)
 {
   if(parentNode == nullptr)
   {
     return;
   }

   parentNode -> key.SerializeStudent(oFile);
   SerializeStudentBSTHelper(oFile, parentNode -> left);
   SerializeStudentBSTHelper(oFile, parentNode -> right);
 }
