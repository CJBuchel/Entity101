#include <iostream>
#include <string>
#include <windows.h>

#include <cassert>

#include "loosescrew/pinches/PinchPoint.h"
#include "loosescrew/lib/lib101.h"
#include "entity.h"

using namespace std;


void TestNameLength() {
  Greeter g("GradleUser");
  std::cout << "[test] returns the correct name length..." << std::flush;
  assert(g.GetNameLength() == 10);
  std::cout << " pass" << std::endl;
}

int main(int argc, char** argv) {
	cout << "Program Running" << endl;
    if (pinchTest && lib101Test) {
      cout << "Test Lib Complete. Program Has Run With Execution Of 1";
    }
    if (!pinchTest) {
      cout << "PinchPoint Has Not Passed Test";
    }
    if (!lib101Test) {
      cout << "Library Test Has Not Passed Test";
    }
    else
    {
      cout << "Tests Have failed. Unknown Cause";
    }
  TestNameLength();
	system("pause");
  return 0;
}