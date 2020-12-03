/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

 #ifndef PERSON_H_
 #define PERSON_H_

 #include <iostream>
 using namespace std;

 #include <iomanip>
 #include <string>
 #include <fstream>

class Person
{
public:
  Person();
  Person(int newID, string newFirstName, string newLastName);
  ~Person();

  //getters and setters
  int GetID();
  string GetFirstName();
  string GetLastName();
  void SetFirstName(string newFirstName);
  void SetLastName(string newLastName);


  virtual void PrintPerson(ostream& oFile) const = 0;

  //overloaded operators
  friend ostream& operator<<(ostream& oFile, const Person& person);
  friend bool operator==(const Person& person1, const Person& person2);
  friend bool operator!=(const Person& person1, const Person& person2);
  friend bool operator>(const Person& person1, const Person& person2);
  friend bool operator<(const Person& person1, const Person& person2);
  friend bool operator>=(const Person& person1, const Person& person2);
  friend bool operator<=(const Person& person1, const Person& person2);

protected:
    void PrintPersonAttributes(ostream& oFile) const;
    int    id;
    string firstName;
    string lastName;

private:
  //n/a

};

 #endif // PERSON_H_
