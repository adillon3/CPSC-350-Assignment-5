/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 04
 *******************************/


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "DoublyLinkedListNode.h"

//#include "DoublyLinkedList.h"

template <class x>
class LinkedListInterface
{
public:
  virtual void InsertFront(x newValue) = 0;
  virtual void InsertBack(x newValue) = 0;
  virtual x DeleteBack() = 0;
  virtual x DeleteFront() = 0;
  virtual x Delete(x key) = 0;
  virtual DoublyLinkedListNode<x>* Search(x key) = 0;
  virtual DoublyLinkedListNode<x>* GetFront() = 0;
  virtual DoublyLinkedListNode<x>* GetBack() = 0;
  virtual void DisplayForwards(ostream& oFile) const = 0;
  virtual void DisplayBackwards(ostream& oFile) const = 0;
  virtual bool IsEmpty() const = 0;
  virtual int GetSize() const = 0;
  virtual x GetValueAtIndex(int index) const = 0;

};

#endif // LINKEDLIST_H_
