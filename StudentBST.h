/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/
 #ifndef STUDENTBST_H_
 #define STUDENTBST_H_

 #include "GenBST.h"
 #include "Person.h"
 #include "Student.h"


class StudentBST : public GenBST<Student>
{
public:
  void SerializeStudentBST(ostream& oFile);
  void SerializeStudentBSTHelper(ostream& oFile, TreeNode<Student>* parentNode);
};

 #endif // STUDENTBST_H_
