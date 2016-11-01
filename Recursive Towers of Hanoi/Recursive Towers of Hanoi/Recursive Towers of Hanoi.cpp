// Recursive Towers of Hanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

using namespace std;

void towers(int, char, char, char);
void print();

int _tmain(int argc, _TCHAR* argv[])
{
	//Get number of discs to use
	int discNum;
	cout << "Enter number of discs to use: ";
	cin >> discNum;
	cout << endl << endl;

	fstream logFile;
	logFile.open("log.txt", std::fstream::out|std::fstream::trunc);
	logFile << "There were "<<discNum <<" discs"<< endl;
	logFile.close();


	//Run solution
	towers(discNum, 'A', 'B', 'C');

	std::cout << "Move list saved in log file" << std::endl;
	system("pause");
	return 0;
}

//Recursive solving function
void towers(int depth, char startBase, char midBase, char endBase)
{
	fstream logFile;
	logFile.open("log.txt", fstream::app);

	//Exit recursion if the first disc is reached
	if (depth == 1)
	{
		logFile << "Moved disc 1 from " << startBase << " to " << endBase << endl;
		return;
	}

	else
	{
		//Move piece from the start to the middle
		towers(depth - 1, startBase, endBase, midBase);

		logFile << "Moved disc " << depth << " from " << startBase << " to " << endBase << endl;

		//Move the middle to the end
		towers(depth - 1, midBase, startBase, endBase);

		logFile.close();
	}
}

//Prints each move
void print()
{

}