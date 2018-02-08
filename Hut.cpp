/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the Hut class. It defines the 
** pure virtual functions that it inherits from Space. 
*********************************************************************/ 
#include "Hut.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;




/*********************************************************************
** Description: The areaInfo function prints out a location tag
*********************************************************************/
void Hut::areaInfo()
{
	cout << "Back in your stately hut." << endl << endl;
}



/*********************************************************************
** Description: The menu function prints out the options available and 
** returns the char chosen.
*********************************************************************/
char Hut::menu()
{
	cout << "What is your wish? Please enter a letter:" << endl;
	cout << "S - Search inside hut" << endl;
	cout << "E - Eat scrumptious potato and worry about bear later" << endl;
	cout << "L - Leave hut" << endl;
	cout << "I - Inventory the potato sack" << endl;
	cout << "R - Review map and notes" << endl;
	cout << "X - Exit game" << endl;

	string hut_chars = "SELIRX";
	char answer = validateChar(hut_chars);

	return answer;
}



/*********************************************************************
** Description: The displaySpace function opens and prints out the txt
** file depicting the location.
*********************************************************************/
void Hut::displaySpace()
{
	std::ifstream inputFile;
	inputFile.open("hut.txt");

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
Hut::~Hut()
{
	//
}