/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Mountain class. It inherits from Space,  
** and represents the mountains where the bear lives. 
*********************************************************************/ 

#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include "Space.hpp"


class Mountain : public Space
{
private:
	//
public:
	Mountain(std::string name) : Space(name) {};
	virtual void areaInfo();
	virtual char menu();
	virtual void displaySpace();
	virtual ~Mountain();
};

#endif