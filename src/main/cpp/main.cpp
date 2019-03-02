#include "greeting.h" 

#include <iostream>  
#include <windows.h>

int main(int argc, char** argv) {
  std::cout << greeting << std::endl;
  system("pause");
  return 0;
}


#include <iostream>
#include <string>
#include <windows.h>

#include <cassert>

#include "loosescrew/pinches/PinchPoint.h"
#include "loosescrew/lib/lib101.h"
#include "entity.h"

using namespace std;

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
  std::cout << greeting << std::endl;
	system("pause");
  return 0;
}
