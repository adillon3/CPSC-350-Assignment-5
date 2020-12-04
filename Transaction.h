/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

 #ifndef TRANSACTION_H_
 #define TRANSACTION_H_

 #include "Student.h"
 #include "Faculty.h"

enum TransactionType
{
  REMOVAL,
  ADDITION,
  MODIFICATION
};

class Transaction
{
public:
  Transaction();
  Transaction(Person* newPerson, string newPersonType, TransactionType newType);
  ~Transaction();

  Person* GetPerson();
  string GetPersonType();
  TransactionType GetType();


private:
  Person* person;
  string personType;
  TransactionType type;
};

 #endif /* TRANSACTION_H_ */
