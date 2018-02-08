/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Field class. It inherits from Space,  
** and represents a potato field, wherefrom a player can resupply on 
** potatoes. There are two: one gives more potatoes but might get attacked, 
** the other gives less, but is safe from the bear.
*********************************************************************/ 

#ifndef FIELD_HPP
#define FIELD_HPP

#include "Space.hpp"



class Field : public Space
{
private:
	//
public:
	Field(std::string name) : Space(name) {};
	virtual void areaInfo();
	virtual char menu();
	virtual void displaySpace();
	virtual ~Field();
};

#endif