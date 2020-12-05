#ifndef TRANSACTION2_H_
#define TRANSACTION2_H_

#include "Student.h"
#include "Faculty.h"
#include "StudentBST.h"
#include "FacultyBST.h"

/*
enum TransactionType2
{
  REMOVAL,
  ADDITION,
  MODIFICATION
};*/

class Transaction2
{
public:
  Transaction2();
  Transaction2(StudentBST newStudentTree, FacultyBST newFacultyTree);
  //Transaction(const Transaction)
  ~Transaction2();

  StudentBST GetStudentTree();
  FacultyBST GetFacultyTree();

private:
  StudentBST* studentTree;
  FacultyBST* facultyTree;

};
 #endif // TRANSACTION2_H_
