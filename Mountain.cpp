/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the Mountain class. It defines the 
** pure virtual functions that it inherits from Space. 
*********************************************************************/ 
#include "Mountain.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;





/*********************************************************************
** Description: The areaInfo function prints out a location tag
*********************************************************************/
void Mountain::areaInfo()
{
	cout << "You are in the nesting place of a ferocious bear! There is no avoiding "
		 << "bear if you come here." << endl << endl;
}



/*********************************************************************
** Description: The menu function prints out the options available and 
** returns the char chosen.
*********************************************************************/
char Mountain::menu()
{
	cout << "What would you like to do? Please enter a letter:" << endl;
	cout << "C - Confront bear" << endl;
	cout << "L - Leave Mountain" << endl;
	cout << "I - Inventory the potato sack" << endl;
	cout << "R - Review map and notes" << endl;
	cout << "X - Exit game" << endl;

	string mountain_chars = "CLIRX";
	char answer = validateChar(mountain_chars);

	return answer;
}


/*********************************************************************
** Description: The displaySpace function opens and prints out the txt
** file depicting the location.
*********************************************************************/
void Mountain::displaySpace()
{
	std::ifstream inputFile;
	inputFile.open("mountains.txt");

	if (inputFile)
	{
		while (inputFile)
		{
			string line;
			getline(inputFile, line);
			cout << line << endl;
		}

		inputFile.close();
	}
	else
	{
		cout << "Error opening file." << endl;
	}
}




/*********************************************************************
** Description: Empty virtual destructor
*********************************************************************/
Mountain::~Mountain()
{
	//
}

