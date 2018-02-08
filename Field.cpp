/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the Field class. It defines the 
** pure virtual functions that it inherits from Space. 
*********************************************************************/ 
#include "Field.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;




/*********************************************************************
** Description: The areaInfo function prints out a location tag
*********************************************************************/
void Field::areaInfo()
{
	if(name == "potato field of dreams")
	{
		cout << "Potato field of dreams is promising very lucrative harvest, "
			 << "but bear will sometimes rampage here." << endl << endl;
	}
	else if (name == "stingy potato field")
	{
		cout << "Stingy potato field is safe from bear, but uncharitable with potatoes." << endl << endl;
	}
}



/*********************************************************************
** Description: The menu function prints out the options available and 
** returns the char chosen.
*********************************************************************/
char Field::menu()
{
	cout << "What is your wish? Please enter a letter:" << endl;
	cout << "P - Plough field" << endl;
	cout << "L - Leave field" << endl;
	cout << "I - Inventory the potato sack" << endl;
	cout << "R - Review map and notes" << endl;
	cout << "X - Exit game" << endl;

	string field_chars = "PLIRX";
	char answer = validateChar(field_chars);

	return answer;
}



/*********************************************************************
** Description: The displaySpace function opens and prints out the txt
** file depicting the location.
*********************************************************************/
void Field::displaySpace()
{
	string filename; 

	if (name == "potato field of dreams")
	{
		filename = "field_1.txt";
	}
	else if (name == "stingy potato field")
	{
		filename = "field_2.txt";
	}

	std::ifstream inputFile;
	inputFile.open(filename);

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
Field::~Field()
{
	//
}