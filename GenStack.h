/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

 #ifndef GENSTACK_H_
 #define GENSTACK_H_

 #include <iostream>
 using namespace std;

template <class x>
class GenStack
{
  public:
    GenStack()
    {
      myArray = new x[128];
      mSize = 128;
      top = -1;
    }

    GenStack(int newMSize)
    {
      myArray = new x[newMSize];
      mSize = newMSize;
      top = -1;
    }

    ~GenStack()
    {
      delete[] myArray;
    }

    void Push(x data)
    {
      //check if stack is isFull
      if(IsFull())
      {
        ResizeArray();
      }
      myArray[++top] = data;
    }

    x Pop() throw (runtime_error)
    {
      if(IsEmpty())
      {
        throw runtime_error("Stack is empty");
      }

      return myArray[top--];
    }

    x Peek()
    {
      if(!IsEmpty())
      {
        return myArray[top];
      }
      else
      {
        throw "Stack Empty";
      }
    }

    void ResizeArray()
    {
      mSize *= 2;
      x* newStack = new x[mSize];

      for (int i = 0; i < mSize; i++)
      {
          newStack[i] = myArray[i];
      }
    }

    bool IsFull()
    {
      return (top == mSize - 1);
    }

    bool IsEmpty()
    {
      if(top == -1)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    int  GetSize()
    {
      return top + 1;
    }

//REMOVE THESE WHEN DONE TESTING
    void PrintStackTopToBottom()
    {
      if(IsEmpty())
      {
        //cout << "Stack empty\n";
        return;
      }

      for(int i = top; i > 0; --i)
      {
        cout << myArray[i] << ", ";
      }

      cout << myArray[0] << endl;
    }

    void PrintStackBottomToTop()
    {
      if(IsEmpty())
      {
        cout << "Stack empty\n";
        return;
      }

      for(int i = 0; i < top; ++i)
      {
        cout << myArray[i] << ", ";
      }

      cout << myArray[top] << endl;
    }

  private:
    int top;
    int mSize;
    x* myArray;
};

#endif /* GENSTACK_H_ */
