#include <iostream>

using namespace std;


template <class T>

class GenStack
{

  public:

  int size;
  int top;

  T *myArray;


  GenStack()
  {
    myArray = new T[128];
    size = 128;
    top = -1;
  }

  GenStack(int maxSize)
  {
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
  }

  ~GenStack()
  {
    delete [] myArray;
  }

  void push(T d)
  {

    if(isFull())
    {
      T *tempArray = new T[size * 2];
      for(int i; i < size; i++)
      {
        tempArray[i] = myArray[i];
        cout << tempArray[i] << "," << myArray[i] << endl;
      }

      myArray = tempArray;

      delete [] tempArray;
      delete tempArray;

      size = size * 2;

    }
    myArray[++top] = d;
  }

  T pop()
  {
    if(isEmpty())
    {
      throw "stack is empty";
    }
    char temp = myArray[top--];
    return temp;
  }

  T peek()
  {
    if(isEmpty())
    {
      throw "stack is empty";
    }
    return myArray[top];
  }

  bool isFull()
  {
    return (top == size - 1);
  }

  bool isEmpty()
  {
    return (top == -1);
  }

  int getSize()
  {
    return (top + 1);
  }

};
