/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the Tavern class. It defines the 
** pure virtual functions that it inherits from Space. 
*********************************************************************/ 
#include "Tavern.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;




/*********************************************************************
** Description: The areaInfo function prints out a location tag
*********************************************************************/
void Tavern::areaInfo()
{
	cout << "You've come to the tavern, a first-rate establishment of spirits." << endl << endl;
}



/*********************************************************************
** Description: The menu function prints out the options available and 
** returns the char chosen.
*********************************************************************/
char Tavern::menu()
{
	cout << "What would you like to do? Please enter a letter:" << endl;
	cout << "T - Talk to Babushka" << endl;
	cout << "V - Contemplate meaninglessness of existence and have a vodka" << endl;
	cout << "L - Leave tavern" << endl;
	cout << "I - Inventory the potato sack" << endl;
	cout << "R - Review map and notes" << endl;
	cout << "X - Exit game" << endl;

	string Tavern_chars = "TVLIRX";
	char answer = validateChar(Tavern_chars);

	return answer;
}



/*********************************************************************
** Description: The displaySpace function opens and prints out the txt
** file depicting the location.
*********************************************************************/
void Tavern::displaySpace()
{
	std::ifstream inputFile;
	inputFile.open("tavern.txt");

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
Tavern::~Tavern()
{
	//
}