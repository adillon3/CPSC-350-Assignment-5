/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

#include "Faculty.h"

Faculty :: Faculty()
{}
Faculty :: Faculty(int newID) : Person(newID, " ", " ")
{
  facultyLevel = " ";
  department = " ";
}
Faculty :: Faculty(int newID, string newFirstName, string newLastName, string newFacultyLevel,
  string newDepartment, DoublyLinkedList<int> newAdviseesIDsList) : Person(newID, newFirstName, newLastName)
{
  facultyLevel = newFacultyLevel;
  department = newDepartment;
  adviseesIDsList = newAdviseesIDsList;
}
Faculty :: ~Faculty()
{}

//getters and setters
string Faculty :: GetFacultyLevel()
{
  return facultyLevel;
}
string Faculty :: GetDepartment()
{
  return department;
}
DoublyLinkedList<int> Faculty :: GetAdviseesIDs()
{
  return adviseesIDsList;
}
void Faculty :: SetFacultyLevel(string newFacultyLevel)
{
  facultyLevel = newFacultyLevel;
}
void Faculty :: SetDepartment(string newDepartment)
{
  department = newDepartment;
}
void Faculty :: AddAdvisee(int newAdvisee)
{
  adviseesIDsList.InsertBack(newAdvisee);
}
void Faculty :: RemoveAdvisee(int oldAdvisee)
{
  adviseesIDsList.Delete(oldAdvisee);
}


//virtual methods
void Faculty :: PrintPerson(ostream& oFile) const
{
  oFile << "------------------------------------\n";
  oFile << "* Faculty *\n";
  PrintPersonAttributes(oFile);
  oFile << "------------------------------------\n";
  oFile << "Level:   " << facultyLevel << endl;
  oFile << "Dept:    " << department << endl;

  PrintAdvisees(oFile);

  oFile << "------------------------------------\n\n";
}


void Faculty :: SerializeFaculty(ostream& oFile)
{
  oFile << id << endl;
  oFile << firstName << endl;
  oFile << lastName << endl;
  oFile << facultyLevel << endl;
  oFile << department << endl;

  for(int i = 0; i < adviseesIDsList.GetSize(); ++i)
  {
    oFile << adviseesIDsList.GetValueAtIndex(i) << endl;
  }


  oFile << endl; // extra space to have seperation between students
}

void Faculty :: PrintAdvisees(ostream& oFile) const
{
  oFile << "Advisees' IDs:\n";

  if(adviseesIDsList.IsEmpty())
  {
    oFile << " - No Advisees Found\n";
  }
  else
  {
    for(int i = 0; i < adviseesIDsList.GetSize(); ++i)
    {
      oFile << " - " << adviseesIDsList.GetValueAtIndex(i) << endl;
    }
  }
}
