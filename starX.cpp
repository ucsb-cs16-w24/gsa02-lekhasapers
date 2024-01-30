// starX.cpp

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void assertEquals(string expected, string actual, string message);
string starX(int width);
void runTests(void);

string starX(int width) {
    if (width < 3 || width % 2 != 1) {
        return "";
    }
    string result = "";

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == j || i + j == width - 1) {
                result += "*";
            } else {
                result += " ";
            }
        }
        result += "\n";
    }
    return result;
}



// Test-Driven Development;
// check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starX3Expected =
      "* *\n"
      " * \n"
      "* *\n";

  assertEquals(starX3Expected, starX(3), "starX(3)");

  string starX5Expected =
      "*   *\n"
      " * * \n"
      "  *  \n"
      " * * \n"
      "*   *\n";

  assertEquals(starX5Expected, starX(5), "starX(5)");

  assertEquals("", starX(0), "starX(0)");
  assertEquals("", starX(2), "starX(2)");
  assertEquals("", starX(4), "starX(4)");
}

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
	if (argc !=2)
	{
		cerr << "Usage: " << argv[0] << "width" << endl;
		exit(1);
	}
	int width= stoi(argv[1]);
	if (width == -1) {
		runTests();
		exit(0);
	}

	cout << starX(width);
  return 0;

}

