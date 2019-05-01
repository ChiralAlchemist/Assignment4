// Assignment4.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "UiUtils.h"
#include <iostream>

int main()
{
	UiUtils programUi;
	programUi.sendOutput("Welcome to Word Freak");
	//programUi.startingOperations();
	bool running = true;
	while (running)
	{
		programUi.sendOutput("Please enter the file name you wish to analyze");
		string fileToAnalyze;
		programUi.openFile();		
		//Run analysis

		//get special words
		programUi.sendOutput("Enter special words");

		//print out p
	}
	
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
