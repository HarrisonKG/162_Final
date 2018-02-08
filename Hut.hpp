/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Hut class. It inherits from Space,  
** and represents the player's house. 
*********************************************************************/ 

#ifndef HUT_HPP
#define HUT_HPP

#include "Space.hpp"



class Hut : public Space
{
private:
	//
public:
	Hut(std::string name) : Space(name) {};
	virtual void areaInfo();
	virtual char menu();
	virtual void displaySpace();
	virtual ~Hut();
};

#endif