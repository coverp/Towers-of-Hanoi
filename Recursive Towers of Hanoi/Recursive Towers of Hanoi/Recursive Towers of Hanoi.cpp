// Recursive Towers of Hanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <vector>
#include<windows.h>

using namespace std;

void towers(int, char, char, char);
void print();

int discNum;
vector < vector<int> > tower;

int _tmain(int argc, _TCHAR* argv[])
{
	//Get number of discs to use
	cout << "Enter number of discs to use: ";
	cin >> discNum;
	cout << endl;

	//Create and populate the tower vector for tracking
	vector <int> a, b, c;

	tower.push_back(a);
	tower.push_back(b);
	tower.push_back(c);

	for (int i = 0; i < discNum; i++)
		tower.at(0).push_back(discNum - i);

	//Print the number of discs to the log file
	fstream logFile;
	logFile.open("log.txt", std::fstream::out|std::fstream::trunc);
	logFile << "There were "<<discNum <<" discs"<< endl;
	logFile.close();

	print();

	//Run solution
	towers(discNum, 'A', 'B', 'C');

	std::cout << "Move list saved in log.txt file" << std::endl<<std::endl;
	system("pause");
	return 0;
}

//Recursive solving function
void towers(int depth, char startBase, char midBase, char endBase)
{
	fstream logFile;
	int source = startBase - 65;
	int dest = endBase - 65;
	logFile.open("log.txt", fstream::app);



	//Exit recursion if the first disc is reached
	if (depth == 1)
	{
		logFile << "Moved disc 1 from " << startBase << " to " << endBase << endl;
		tower.at(dest).push_back(tower.at(source).at(tower.at(source).size() - 1 ));
		tower.at(source).pop_back();

		print();

		return;
	}

	else
	{
		//Move stack of pieces from the start to the middle
		towers(depth - 1, startBase, endBase, midBase);
		tower.at(dest).push_back(tower.at(source).at(tower.at(source).size() - 1));
		tower.at(source).pop_back();

		print();

		logFile << "Moved disc " << depth << " from " << startBase << " to " << endBase << endl;

		//Move stack of pieces from the middle to the end
		towers(depth - 1, midBase, startBase, endBase);

		logFile.close();
	}
}

//Prints each move
void print()
{
	//Sleeps for a certain amount of time, speeding up with the complexity of the problem
	if (discNum < 7)
		Sleep(1000 / discNum);

	else
		Sleep(500 / discNum);

	//Loop through each base
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			std::cout << "A\t";
			break;
		case 1:
			std::cout << "B\t";
			break;
		case 2:
			std::cout << "C\t";
			break;
		}

		//make a table 3 deep and discNum wide
		if (tower.at(i).size()>0)
		{	

			for (int j = 0; j < tower.at(i).size(); j++)
				std::cout << tower.at(i).at(j) << "\t";
		}
		//print contents in table
		std::cout << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl;
}