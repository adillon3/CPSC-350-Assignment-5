/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"

class Student : public Person
{
public:
  Student();
  Student(int newID);
  Student(int newID, string newFirstName, string newLastName, string newStudentLevel,
    string newMajor, double newGPA, int newAdvisorID);
  ~Student();

  //getters and setters
  string GetStudentLevel();
  string GetMajor();
  double GetGPA();
  int GetAdvisorID();
  void SetStudentLevel(string newStudentLevel);
  void SetMajor(string newMajor);
  void SetGPA(double newGPA);
  void SetAdvisorID(int newAdvisorID);


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

  void SerializeStudent(ostream& oFile);

private:
  static int makeStudentID();

  string studentLevel;
  string major;
  double gpa;
  int    advisorID;
};

 #endif // STUDENT_H_
