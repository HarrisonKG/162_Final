/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Space class, an abstract base class. 
** Space represents the locations that the player can travel to. Spaces
** are linked via cardinal direction pointers, and each derived class
** defines its own location tagline, menu, and image display. 
*********************************************************************/ 

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <fstream>
#include "validateInput.hpp"



class Space
{
protected:
	Space* north;
	Space* east;
	Space* south;
	Space* west;

	std::string name;

public:
	Space(std::string spaceName);
	std::string getName();
	
	// returns the Spaces pointed to in each direction
	Space* getNorth();
	Space* getEast();
	Space* getSouth();
	Space* getWest();

	// set links between spaces
	void setNorth(Space* space);
	void setEast(Space* space);
	void setSouth(Space* space);
	void setWest(Space* space);

	// purely virtual functions
	virtual void areaInfo() = 0;
	virtual char menu() = 0;
	virtual void displaySpace() = 0;
	
	virtual char travelMenu();
	virtual ~Space();
};

#endif
