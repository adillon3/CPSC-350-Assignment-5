/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/
  #include "Transaction.h"

  Transaction :: Transaction()
  {
    person = nullptr;
  }
  Transaction :: Transaction(Person* newPerson, TransactionType newType)
  {
    person = newPerson;
    type = newType;
  }
  Transaction :: ~Transaction()
  {
    delete person;
  }

  Person* Transaction :: GetPerson()
  {
    return person;
  }
  TransactionType Transaction :: GetType()
  {
    return type;
  }
