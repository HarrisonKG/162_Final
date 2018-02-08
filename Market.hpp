/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Market class. It inherits from Space,  
** and represents a village marketplace. There are two: the player's
** home village, and a neighboring one. 
*********************************************************************/ 

#ifndef MARKET_HPP
#define MARKET_HPP

#include "Space.hpp"
#include <vector>



class Market : public Space
{
private:
	struct Wares
	{
		std::string description;
		std::string name;
		int cost;
		Wares(std::string d, std::string n, int c);
	};
	std::vector<Wares> marketWares;
public:
	Market(std::string name);
	virtual void areaInfo();
	virtual char menu();
	virtual void displaySpace();
	void printWares();
	int getCost(int newItem);
	std::string getName(int newItem);
	virtual ~Market();
};

#endif