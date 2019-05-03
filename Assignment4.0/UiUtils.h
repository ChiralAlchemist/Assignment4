#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Color.h"

using namespace std;
class UiUtils
{
public:
	UiUtils();
	UiUtils(const UiUtils& anotherUi);
	~UiUtils();
	void startingOperations();
	string addMargin(int marginAmount);
	bool checkInput(string input, vector<string> acceptedInput);
	void recieveInput(string& var, vector<string> acceptedInput = {});
	void recieveLineFromFile(string& var);
	void openFile();
	void sendOutput(string str, int marginAmount = 0, bool out = false);
	void conformationOutput(string str);

private:
	ifstream inFile;
	ofstream outFile;
	bool run;
	string inputType;
	string outputType;
};

