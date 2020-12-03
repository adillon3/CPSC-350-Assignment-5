/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

 #ifndef SCHOOLDATABASE_H_
 #define SCHOOLDATABASE_H_

 #include <sstream>

 #include "Student.h"
 #include "Faculty.h"
 #include "StudentBST.h"
 #include "FacultyBST.h"
 #include "GenStack.h"
 #include "Transaction.h"

 class SchoolDatabase
 {
 public:
   SchoolDatabase();
   ~SchoolDatabase();

   void RunDatabase();

   //Main methods for menu operations
   void PrintStudentDatabase();
   void PrintFacultyDatabase();
   void PrintStudentFromID(); //Prompt for Student ID and call helper method
   void PrintFacultyFromID(); //Prompt for Student ID and call helper method
   void PrintStudentAdvisor(); //Promprt for ID, calls helper to search and print
   void PrintFacultyAdvisees(); //Promprt for ID, calls helper to search and print
   void AddStudent();
   void DeleteStudent(); //Given ID
   void AddFaculty();
   void DeleteFaculty(); //Given ID
   void ChangeStudentAdvisor(); //Prompt for student id and the new faculty id
   void RemoveAdviseeFromID(); //Prompt for facilty ID and student ID
   void Rollback(); //Remove last action from the stack and undo last method

 private:
   //Private Methods
   int GetMenuInput(const string initialMessage, const int numMenuOptions);
   bool CheckFileNameValid(string fileName);
   bool GetYesOrNoInput(const string initialMessage);
   //int GetNewAdvisorID(const int facultyToDeleteFrom);

   int GenerateStudentID();
   int GenerateFacultyID();

   //Sereialization
   void SerializeStudents();
   void SerializeFaculty();
   void DeserializeStudents(string fileName);
   void DeserializeFaculty(string fileName);

   void AddStudentIDToFacultyTree(int newAdvisorID, int newID);
   void RemoveStudentIDFromFacultyTree(int newAdvisorID, int newID);

   //Data fields
   StudentBST studentTree;
   FacultyBST facultyTree;

   GenStack<Transaction> transactionStack;

   const string MAIN_MENU = "* MAIN MENU *\n"
                            "1.  Print all students and their information\n"
                            "2.  Print all faculty and their information\n"
                            "3.  Print student from ID\n"
                            "4.  Print faculty from ID\n"
                            "5.  Print student advisor info from student ID\n"
                            "6.  Print faculty advisees from faculty ID\n"
                            "7.  Add a new student\n"
                            "8.  Delete a student from their ID\n"
                            "9.  Add a new faculty member\n"
                            "10. Delete a faculty from their ID\n"
                            "11. Change a student’s advisor from their IDs\n"
                            "12. Remove an advisee from a faculty member from their IDs\n"
                            "13. Rollback\n"
                            "14. Exit\n"
                            "Choice: ";
   const int NUM_MAIN_MENU_OPTIONS = 14;
 };

 #endif // SCHOOLDATABASE_H_
