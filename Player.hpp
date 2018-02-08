/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Player class, which represents the 
** user playing the game. Player tracks attributes such as current  
** location and number of potatoes remaining, and contains the actions 
** the user can decide to play. 
*********************************************************************/ 

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Space.hpp"



class Player
{
private:
	Space* location;
	int potatoes; 
	std::vector<std::string> sack;
	static const int sack_max = 6;

	bool starved = false;
	bool won = false;
	bool firstWarning = false;
	bool secondWarning = false;
	
public:
	Player();
	
	void travel();
	void barter();
	void talk();
	void plough();
	void search();
	void eat();
	void vodka();
	void confront();

	bool addToSack(std::string item);
	void removeFromSack();
	bool armed(std::string item);
	void chanceOfAttack();
	void chanceOfHunger();
	void potatoWarnings();
	
	// accessors
	int getPotatoes();
	Space* getLocation();
	bool getWon();
	bool getStarved();
	
	// mutators
	void setPotatoes(int gainOrLoss);
	void setLocation(Space* newSpace);

	~Player();
};

#endif