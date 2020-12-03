/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

#include "Person.h"

Person :: Person()
{}

Person :: Person(int newID, string newFirstName, string newLastName)
{
  id = newID;
  firstName = newFirstName;
  lastName = newLastName;
}

Person :: ~Person()
{}

//getters and setters
int Person :: GetID()
{
  return id;
}
string Person :: GetFirstName()
{
  return firstName;
}
string Person :: GetLastName()
{
  return lastName;
}
void Person :: SetFirstName(string newFirstName)
{
  firstName = newFirstName;
}
void Person :: SetLastName(string newLastName)
{
  lastName = newLastName;
}

//virtual methods
void Person :: PrintPerson(ostream& oFile) const
{}

//protected methods
void Person :: PrintPersonAttributes(ostream& oFile) const
{
  oFile << "ID:   " << id << endl;
  oFile << "Name: " << lastName << ", " << firstName << endl;
}



//Friend functions
ostream& operator<<(ostream& oFile, const Person& person)
{
  person.PrintPerson(oFile);
}
bool operator==(const Person& person1, const Person& person2)
{
  if(person1.id == person2.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator!=(const Person& person1, const Person& person2)
{
  if(person1.id != person2.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator>(const Person& person1, const Person& person2)
{
  if(person1.id > person2.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator<(const Person& person1, const Person& person2)
{
  if(person1.id < person2.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator>=(const Person& person1, const Person& person2)
{
  if(person1.id >= person2.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator<=(const Person& person1, const Person& person2)
{
  if(person1.id <= person2.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}
