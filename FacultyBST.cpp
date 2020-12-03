/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/
 #include "FacultyBST.h"

 void FacultyBST :: SerializeFacultyBST(ostream& oFile)
 {
   SerializeFacultyBSTHelper(oFile, root);
 }
 void FacultyBST :: SerializeFacultyBSTHelper(ostream& oFile, TreeNode<Faculty>* parentNode)
 {
   if(parentNode == nullptr)
   {
     return;
   }

   parentNode -> key.SerializeFaculty(oFile);
   SerializeFacultyBSTHelper(oFile, parentNode -> left);
   SerializeFacultyBSTHelper(oFile, parentNode -> right);
 }

 int FacultyBST :: GetANewIDFacultyMemberID(int oldFacultyID)
 {
   int newFacultyID = 0;

   GetANewIDFacultyMemberIDHelper(root, oldFacultyID, newFacultyID);

   return newFacultyID;
 }

 void FacultyBST :: GetANewIDFacultyMemberIDHelper(TreeNode<Faculty>* current, int oldFacultyID, int &newFacultyID)
 {
   if(current == nullptr)
   {
     return;
   }

   if(current -> key.GetID() != oldFacultyID)
   {
     newFacultyID = current -> key.GetID();
     return;
   }

   GetANewIDFacultyMemberIDHelper(current -> left, oldFacultyID, newFacultyID);
   if(newFacultyID != 0)
   {
     return;
   }
   GetANewIDFacultyMemberIDHelper(current -> right, oldFacultyID, newFacultyID);
 }
