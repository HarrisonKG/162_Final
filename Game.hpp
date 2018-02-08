/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the header file for the Game class, which contains 7 Space*
** pointers and a Player object, and controls overall game flow. 
*********************************************************************/ 


#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "Player.hpp"
#include <vector>



class Game 
{
private:
	Space* market_1;
	Space* market_2;
	Space* field_1;
	Space* field_2;
	Space* hut;
	Space* mountain;
	Space* tavern;
	Player milosh;
public:
	Game();
	void playGame();
	void gameIntro();
	void printNotes();
	void printMap();
	void review();
	void takeAction(char userChoice);
	bool won();
	bool starved();
	~Game();
};

#endif