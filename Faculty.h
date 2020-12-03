/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

 #ifndef FACULTY_H_
 #define FACULTY_H_

 #include "Person.h"
 #include "DoublyLinkedList.h"

 class Faculty : public Person
 {
 public:
  Faculty();
  Faculty(int newID);
  Faculty(int newID, string newFirstName, string newLastName,
    string newFacultyLevel, string newDepartment, DoublyLinkedList<int> newAdviseesIDsList);
  ~Faculty();

  //getters and setters
  string GetFacultyLevel();
  string GetDepartment();
  DoublyLinkedList<int> GetAdviseesIDs();
  void SetFacultyLevel(string newFacultyLevel);
  void SetDepartment(string newDepartment);
  void AddAdvisee(int newAdvisee);
  void RemoveAdvisee(int oldAdvisee);


  //virtual methods
  void PrintPerson(ostream& oFile) const;
  //friend ostream& operator<<(ostream& oFile, const & object person);

  //methods fom super
  /*
  int GetID();
  string GetFirstName();
  string GetLastName();
  void SetFirstName(string newFirstName);
  void SetLastName(string newLastName);*/

  void SerializeFaculty(ostream& oFile);
  void PrintAdvisees(ostream& oFile) const;

 private:
  static int makeFacultyID();


  string facultyLevel;
  string department;
  DoublyLinkedList<int> adviseesIDsList;



 };

  #endif // FACULTY_H_
