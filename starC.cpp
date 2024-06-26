// starC.cpp
// A demonstration of ASCII Art printing C characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starC(int width, int height);
void runTests(void);

// Write starC per specifictions in the lab writeup

string starC(int width, int height)
{
if (height < 3 || width < 2) {
	return "";
}
  string result = "";
  result += string(width,'*') + "\n";
 for (int i = 1; i < height-1; ++i) {
	result +='*' + string(width-1,' ') + "\n";
 } 
 result += string(width,'*') + "\n";
	// TODO: remove this line, replace with correct code
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starC34Expected =
      "***\n"
      "*  \n"
      "*  \n"
      "***\n";

  assertEquals(starC34Expected, starC(3, 4), "starC(3,4)");

  string starC53Expected =
      "*****\n"
      "*    \n"
      "*****\n";

  assertEquals(starC53Expected, starC(5, 3), "starC(5,3)");

  assertEquals("", starC(2, 1), "starC(2,1)");
  assertEquals("", starC(2, 2), "starC(2,2)");

  string starC23Expected =
      "**\n"
      "* \n"
      "**\n";

  assertEquals(starC23Expected, starC(2, 3), "starC(2,3)");
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
{if (argc != 3) {
	cerr <<"Usage: "<< argv[0] << " width height" << endl;
       return(1);
		}
int width= stoi(argv[1]);
int height = stoi(argv[2]);

if( width == -1 && height == -1)
{
	runTests();
}
cout << starC(width,height);
return 0 ;
}

  // TODO: Add check for parameters
  // and code to print usage message

  // TODO: Add code to get width and height from cmd line args
  // code that checks if they are both -1; if so, call runTests()
  // then exit.
