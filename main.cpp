#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv)
{
  string fpath = "test.txt";
  if(argv[0] == NULL)
  {

    fpath = argv[0];
  }
bool exit = false;
  while(!exit){

  ifstream inFile(fpath);

  GenStack<char> delimiters = GenStack<char>();
  if(inFile.is_open())
  {

    string line;
    int count = 0;
    while (getline(inFile, line))
    {
        count++;
        int charNum = 0;

        for(char& c : line)
        {
          charNum++;
          if((c == '(') | (c == '[') | (c == '{'))
          {
            delimiters.push(c);
          }
          if((c == ')') | (c == ']') | (c == '}'))
          {
            try
            {
              char eval = delimiters.pop();

              if(!(eval == '(' && c == ')') && !(eval == '[' && c == ']') && !(eval == '{' && c == '}'))
              {
                  cout << "Line " << count << ": expected mate to " << eval << " and found " << c << " at character " << charNum << endl;
                  throw "Open Missing Closed";
              }
            }

            catch(...)
            {
              cout << "Line " << count << ": expected mate and found " << c << " at character " << charNum << endl;
              throw "Closed Missing Open";
            }


          }


        }

    }

    if(!delimiters.isEmpty())
    {
      cout << "Reached end of file missing matches for:"<< endl;
      while (!delimiters.isEmpty()) {
        cout << delimiters.pop() << endl;
      }
      throw "Closed Missing Open";
    }

    cout << "no errors" << endl;
  }

  cout << "Enter a filepath to run again, or type X to exit" << endl;

  string ex = "";
  cin >> ex;

  if(ex == "X" || ex == "x")
  {
    exit = true;
  }
  fpath = ex;
}

}
