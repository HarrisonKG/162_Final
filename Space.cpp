/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the abstract base class. Individual
** descriptions are below.
*********************************************************************/ 
#include "Space.hpp"
#include <cstdlib>
#include <iostream>
using std::string;
using std::cout;
using std::endl;



/*********************************************************************
** Description: Space constructor initializes the space's name, and
** sets all its directional pointers to null
*********************************************************************/
Space::Space(string spaceName)
{
	name = spaceName;

	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
}



/*********************************************************************
** Description: Returns the space's name
*********************************************************************/
string Space::getName()
{
	return name;
}



/*********************************************************************
** Description: Returns the space to the north
*********************************************************************/
Space* Space::getNorth()
{
	return north;
}



/*********************************************************************
** Description: Returns the space to the east
*********************************************************************/
Space* Space::getEast()
{
	return east;
}



/*********************************************************************
** Description: Returns the space to the south
*********************************************************************/
Space* Space::getSouth()
{
	return south;
}



/*********************************************************************
** Description: Returns the space to the west
*********************************************************************/
Space* Space::getWest()
{
	return west;
}



/*********************************************************************
** Description: Sets the north pointer
*********************************************************************/
void Space::setNorth(Space* space)
{
	north = space;
}



/*********************************************************************
** Description: Sets the east pointer
*********************************************************************/
void Space::setEast(Space* space)
{
	east = space;
}



/*********************************************************************
** Description: Sets the south pointer
*********************************************************************/
void Space::setSouth(Space* space)
{
	south = space;
}



/*********************************************************************
** Description: Sets the west pointer
*********************************************************************/
void Space::setWest(Space* space)
{
	west = space;
}



/*********************************************************************
** Description: The travelMenu function prints out a menu prompt and 
** prints all directions that are not null (i.e. are valid to travel to).
*********************************************************************/
char Space::travelMenu() 
{
	cout << "In what direction will you be making travel? Please enter a letter:" << endl << endl;
	string validDir = "";

	if (north)
	{
		cout << "N - (north) - " << north->getName() << endl;
		validDir += "N";
	}
	if (east)
	{
		cout << "E - (east)  - " << east->getName() << endl;
		validDir += "E";
	}
	if (south)
	{
		cout << "S - (south) - " << south->getName() << endl;
		validDir += "S";
	}
	if (west)
	{
		cout << "W - (west)  - " << west->getName() << endl;
		validDir += "W";
	}
	cout << endl;
	
	char response = validateChar(validDir);
	
	return response;
}



/*********************************************************************
** Description: The destructor sets all directional pointers to null
*********************************************************************/
Space::~Space()
{
	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
}
