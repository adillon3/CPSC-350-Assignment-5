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
  Transaction :: Transaction(Person* newPerson, string newPersonType, TransactionType newType)
  {
    person = newPerson;
    personType = newPersonType;
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
  string Transaction :: GetPersonType()
  {
    return personType;
  }
  TransactionType Transaction :: GetType()
  {
    return type;
  }
