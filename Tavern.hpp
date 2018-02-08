/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Tavern class. It inherits from Space,  
** and represents a tavern. 
*********************************************************************/ 

#ifndef TAVERN_HPP
#define TAVERN_HPP

#include "Space.hpp"



class Tavern : public Space
{
private:
	//
public:
	Tavern(std::string name) : Space(name) {};
	virtual void areaInfo();
	virtual char menu();
	virtual void displaySpace();
	virtual ~Tavern();
};

#endif