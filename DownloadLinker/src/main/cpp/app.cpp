/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include <iostream>
#include <stdlib.h>
#include "app.h"

#include <Windows.h>
#include <string>

char input;
char yesNo = 'y';

using namespace std;

std::string DownloadLinker::Greeter::greeting() {
    return std::string("Download linker initiated ================= V1.1");
}

int main () {
    DownloadLinker::Greeter greeter; // Project Test Code
    std::cout << greeter.greeting() << std::endl;

    cout << "SetUp Enitiated." << endl;
    const int bufferSize = MAX_PATH;
    char oldDir[bufferSize]; // store the current directory
    
    // get the current directory, and store it
    if (!GetCurrentDirectory(bufferSize, oldDir)) {
        std::cerr << "Error getting current directory: #" << GetLastError();
        return 1; // quit if it failed
    }
    std::cout << "Current directory: " << oldDir << '\n';

 

   

    // Reset the current directory back to what it was.
    if (!SetCurrentDirectory(oldDir)) {
        std::cerr << "Error resetting current directory: #" << GetLastError();
        return 1;
    }
    std::cout << "Reset current directory. \n";
    cout << endl;
    cout << "Please Don't switch off your computer Downloading: "<< endl;

    //------- Download Section
    //-------


    cout << endl << endl;
    cout << "Download Complete, Restart Required (y/n): ";
    cin >> input;
    if(input == yesNo) {
        system("shutdown /r /t 0");
    } else {
        cout << endl << endl;
        cout << "Closing SetUp" << endl;
    }
    system("pause");
    

    return 0;
}
