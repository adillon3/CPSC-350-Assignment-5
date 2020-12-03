/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

 #include "Student.h"

Student :: Student()
{}

Student :: Student(int newID)
{
  id = newID;
  firstName = " ";
  lastName = " ";
  studentLevel = " ";
  major = "";
  gpa = 0;
  advisorID = 0;
}

Student :: Student(int newID, string newFirstName, string newLastName, string newStudentLevel,
   string newMajor, double newGPA, int newAdvisorID) : Person(newID, newFirstName, newLastName)
 {
   studentLevel = newStudentLevel;
   major = newMajor;
   gpa = newGPA;
   advisorID = newAdvisorID;
 }
Student :: ~Student()
 {

 }

 //getters and setters
 string Student :: GetStudentLevel()
 {
   return studentLevel;
 }
 string Student :: GetMajor()
 {
   return major;
 }
 double Student :: GetGPA()
 {
   return gpa;
 }
 int Student :: GetAdvisorID()
 {
   return advisorID;
 }
 void Student :: SetStudentLevel(string newStudentLevel)
 {
   studentLevel = newStudentLevel;
 }
 void Student :: SetMajor(string newMajor)
 {
   major = newMajor;
 }
 void Student :: SetGPA(double newGPA)
 {
   gpa = newGPA;
 }
 void Student :: SetAdvisorID(int newAdvisorID)
 {
    advisorID = newAdvisorID;
 }

 //virtual methods
 void Student :: PrintPerson(ostream& oFile) const
 {
   oFile << "------------------------------------\n";
   oFile << "* Student *\n";
   PrintPersonAttributes(oFile);
   oFile << "------------------------------------\n";
   oFile << "Level:   " << studentLevel << endl;
   oFile << "Major:   " << major << endl;

   oFile << showpoint << setprecision(3);//formating
   oFile << showpoint << "GPA:     " << gpa << endl;
   oFile << noshowpoint << setprecision(6);//resetting formating


   oFile << "Advisor: ";
   //if no advisor
   if(advisorID == 0)
   {
     oFile << "No Advisor Found\n";
   }
   //if Advisor does exist
   else
   {
     oFile << advisorID << endl;
   }

   oFile << "------------------------------------\n\n";
 }

void Student :: SerializeStudent(ostream& oFile)
{
  oFile << id << endl;
  oFile << firstName << endl;
  oFile << lastName << endl;
  oFile << studentLevel << endl;
  oFile << major << endl;
  oFile << gpa << endl;
  oFile << advisorID << endl;
  oFile << endl; // extra space to have seperation between students
}

 /*
 ostream& operator<<(ostream& oFile, const & object persons)
 {
   PrintPerson(oFile);
 }*/
