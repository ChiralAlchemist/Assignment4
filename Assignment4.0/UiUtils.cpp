#include "pch.h"
#include "UiUtils.h"
#include "UiUtils.h"
#include <array>
using namespace std;

UiUtils::UiUtils()
{
	inputType = "F";
	inFile.open("input.txt");
	outFile.open("books.txt");
}

UiUtils::UiUtils(const UiUtils& anotherUi)
{

}

UiUtils::~UiUtils()
{
}

void UiUtils::startingOperations()
{
	string inputString;
	string inputFileName;
	vector<string> expectedInput = { "F", "M" };

	sendOutput("Enter data entry method M for manual F for file entry");
	recieveInput(inputString, expectedInput);

	if (inputString == "F")
	{
		openFile();
	}

	inputType = inputString;
}


string UiUtils::addMargin(int marginAmount)
{
	string margin = "";
	for (int i = 0; i < marginAmount; i++)
	{
		margin += " ";
	}
	return margin;
}

bool UiUtils::checkInput(string input, vector<string> acceptedInput)
{
	for (string word : acceptedInput)
	{
		if (input == word)
		{
			return true;
		}
	}
	string errorMessage = "You entered " + input + ", invalid input please enter ";
	for (unsigned int i = 0; i < acceptedInput.size(); i++)
	{
		if (i == acceptedInput.size() - 1)
			errorMessage += acceptedInput[i] + ".";
		else
			errorMessage += acceptedInput[i] + " or ";
	}
	sendOutput(errorMessage);
	return false;
}

void UiUtils::recieveInput(string& var, vector<string> acceptedInput)
{
	bool nonValidInput = false;
	do
	{
		if (inputType == "M")
		{
			//cin.ignore();
			getline(cin, var);
		}
		if (inputType == "F")
		{
			getline(inFile, var);
			if (var == "")
			{
				sendOutput("Finished with file");
				inputType = "M";
			}
		}

		if (acceptedInput.size() > 0)
		{
			nonValidInput = !checkInput(var, acceptedInput);
		}

		if (var == "Quit")
		{
			nonValidInput = false;
		}
	} while (nonValidInput);
}

void UiUtils::recieveLineFromFile(string & var)
{
	getline(inFile, var);
}

void UiUtils::openFile()
{
	
	string inputFileName;
	do
	{
		sendOutput("Enter input file name.");
		recieveInput(inputFileName);
		inFile.close();
		inFile.open(inputFileName);
		if (inFile.is_open() == false) 
		{
			sendOutput("Invalid Filename please try renter");
		}
	} while (inFile.is_open() == false);
	
	
}

void UiUtils::sendOutput(string str, int marginAmount, bool out)
{
	string margin = addMargin(marginAmount);
	cout << margin + str << endl;
	if (out) {
		outFile << margin + str << endl;
	}
}

void UiUtils::conformationOutput(string str)
{
	cout << green << str << white << endl;
}
