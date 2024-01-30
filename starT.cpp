// starT.cpp   A demonstration of ASCII Art printing T characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starT(int width, int height);
void runTests(void);

// Write starT per specifictions in the lab writeup

string starT(int width, int height)
{
  if (height < 2 ||width <3 || width % 2 == 0){
	  return "";
  }
  string result = "";
  
  result += string(width, '*') + "\n";
  for (int i = 1; i< height; ++i) {
	  result += string(width/2, ' ') + '*' + string(width/2, ' ') +  "\n";
  }
// TODO: remove this line, replace with correct code
	return result;
	}

// Test-Driven Development; check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starT34Expected =
      "***\n"
      " * \n"
      " * \n"
      " * \n";

  assertEquals(starT34Expected, starT(3, 4), "starT(3,4)");

  string starT53Expected =
      "*****\n"
      "  *  \n"
      "  *  \n";

  assertEquals(starT53Expected, starT(5, 3), "starT(5,3)");

  string starT72Expected =
      "*******\n"
      "   *   \n";

  assertEquals(starT72Expected, starT(7, 2), "starT(7,2)");

  assertEquals("", starT(1, 2), "starT(1,2)");
  assertEquals("", starT(5, 1), "starT(5,1)");
  assertEquals("", starT(4, 2), "starT(4,2)");
  assertEquals("", starT(6, 2), "starT(6,2)");
}

// Test harness

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
    ;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

// Main function

int main(int argc, char *argv[])
{
if (argc != 3) {
	cerr << "Usage: " << argv[0] << " width height" << endl;
	return(1);
}
int width = stoi(argv[1]);
int height = stoi(argv[2]);

if (width == -1 && height == -1)
{
	runTests();
	exit(0);
}

cout <<  starT(width, height);
return 0;
}
  // TODO: Add check for parameters
  // and code to print usage message

  // TODO: Add code to get width and height from command line args
  // code that checks if they are both -1; if so, call runTests()
  // then exit.


  // TODO: Add code that calls the starT function and prints
  // the result on cout (without an extra newline)

