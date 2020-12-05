 #include "Transaction2.h"


Transaction2 :: Transaction2()
{

}

Transaction2 :: Transaction2(StudentBST newStudentTree, FacultyBST newFacultyTree)
{
  cerr << "Transaction2(StudentBST newStudentTree, FacultyBST newFacultyTree)\n\n";
  *studentTree = newStudentTree;
  *facultyTree = newFacultyTree;

  if(studentTree == &newStudentTree)
  {
    cerr << "SAME LOCATION";
  }
  else
  {
    cerr << "Different Locationd";
  }

  cerr << endl << endl;

cerr << "about to studentTree -> InOrder();\n\n";
  studentTree -> InOrder();
  //facultyTree.InOrder();
cerr << "End of Transaction2(StudentBST newStudentTree, FacultyBST newFacultyTree)\n\n";


}
//Transaction2(Person* newPerson, string newPersonType, TransactionType newType);
//Transaction(const Transaction)
Transaction2 :: ~Transaction2()
{

}

StudentBST Transaction2 :: GetStudentTree()
{
  cerr << "GetStudentTree\n\n";

  cerr << "ADREESS OF STUDENT TREE: " << &studentTree << endl;
  studentTree -> InOrder();

  return *studentTree;
}
FacultyBST Transaction2 :: GetFacultyTree()
{
  return *facultyTree;
}
