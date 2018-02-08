/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the Game class, which dynamically
** creates and links the Spaces, instantiates a Player, and runs the game.
*********************************************************************/ 
#include "Game.hpp"
#include "Market.hpp"
#include "Field.hpp"
#include "Hut.hpp"
#include "Mountain.hpp"
#include "Tavern.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
using std::string;
using std::cout;
using std::cin;
using std::endl;



/*********************************************************************
** Description: The Game constructor dynamically creates Space objects, 
** and links them using pointers within the Space class. The constructor 
** also instantiates the Player object, and sets its location to market_1.
*********************************************************************/ 
Game::Game()
{
	// create locations
	market_1 = new Market("village market");
	market_2 = new Market("neighboring village market");
	field_1 = new Field("potato field of dreams");
	field_2 = new Field("stingy potato field");
	hut = new Hut("potato hut");
	mountain = new Mountain("mountain");
	tavern = new Tavern("tavern");

	// set pointers
	market_1->setEast(market_2);
	market_1->setNorth(mountain);
	market_1->setSouth(field_1);
	market_2->setWest(market_1);
	market_2->setEast(tavern);
	market_2->setSouth(field_2);
	field_1->setNorth(market_1);
	field_1->setEast(field_2);
	field_1->setWest(hut);
	field_2->setNorth(market_2);
	field_2->setWest(field_1);
	hut->setEast(field_1);
	mountain->setSouth(market_1);
	tavern->setWest(market_2);

	milosh = Player();
	milosh.setLocation(market_1);
}



/*********************************************************************
** Description: The playGame function handles the overall control of 
** the program. It prints introductory messages then loops through action
** menus until the player exits, dies, or wins. At the end of the game
** it deletes the objects dynamically created in the constructor.
*********************************************************************/ 
void Game::playGame() 
{
	gameIntro();
	char userChoice;

	while (userChoice != 'X' && !won() && !starved())
	{		
		// print location, blurb, and menu
		milosh.getLocation()->displaySpace();
		milosh.getLocation()->areaInfo();
		userChoice = milosh.getLocation()->menu(); 
		clearScreen(5);

		// routes control to user's chosen function 
		takeAction(userChoice);

		// check once more in case situation changed because of menu action
		if (userChoice != 'X' && !won() && !starved())
		{
			// random chance of player needing to eat or the bear attacking
			milosh.chanceOfHunger();
			milosh.chanceOfAttack();
		}
	}

	if(won())
	{
		clearScreen();
		cout << "Milosh is celebrated as valiant hero of the village!! " 
			 << "Your people are saved!!" << endl << endl;
		cout << "They will be reveling at a sumptuous feast in your honor tonight." << endl;
		clearScreen(15);
		cout << "THANK YOU FOR PLAYING" << endl << endl;
	}
	else if (starved())
	{
		cout << "Oh no, you succumbed to famine before you could vanquish the bear menace." << endl << endl;
		clearScreen(15);
		cout << "GAME OVER" << endl << endl;
	}
	else 
	{
		clearScreen();
	}

	delete market_1;
	delete market_2;
	delete field_1;
	delete field_2;
	delete hut;
	delete mountain;
	delete tavern;

	market_1 = nullptr;
	market_2 = nullptr;
	field_1 = nullptr;
	field_2 = nullptr;
	hut = nullptr;
	mountain = nullptr;
	tavern = nullptr;
}



/*********************************************************************
** Description: The gameIntro function prints out introductory messages
** to convey the situation, mission, and recommended execution. 
*********************************************************************/ 
void Game::gameIntro() 
{
	clearScreen();

	cout << "You are Milosh!" << endl << endl << endl;
	cout << "A supremely pugnacious bear has been menacing your village!!" << endl << endl << endl;
	cout << "You must vanquish the bear to save your fellow villagers, "
		 << "but you must not run out of potatoes!"; 
	clearScreen(15);
	cout << "Please make sure you are in FULL SCREEN mode" << endl << endl << endl;
	pressEnter("Press enter to examine the map..");
	
	clearScreen(10);
	printMap();
	cout << endl << endl;
	pressEnter("Press enter for further explication..");
	
	clearScreen(10);
	printNotes();
	pressEnter("Press enter to commence this quest...!");
	clearScreen(10);
}



/*********************************************************************
** Description: The printNotes function prints out helpful explanations.
*********************************************************************/ 
void Game::printNotes() 
{
	cout << "Village Hypothesis for the Vanquishing of Bear:" << endl << endl << endl;
	cout << "Go to neighboring village to talk to the Babushka. " << endl << endl;
	cout << "She is wise in the ways of science and will be able to make " 
		 << "tremendous recommendation regarding bear mischief."; 
	clearScreen(8);

	cout << "Explanation of Potato Economy:" << endl << endl << endl;
	cout << "Milosh possesses in this moment " << milosh.getPotatoes() << " potatoes." << endl << endl;
	cout << "- lose potatoes when Milosh is hungry or is making a purchase" << endl << endl;
	cout << "- lose many potatoes if bear is attacking" << endl << endl;
	cout << "+ obtain more potatoes by toiling in fields with donkey plough";
	clearScreen(8);
}



/*********************************************************************
** Description: The printMap function prints out the ascii map.
*********************************************************************/ 
void Game::printMap()
{
	std::ifstream inputFile;
	inputFile.open("map.txt");

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
		cout << "Error opening map." << endl;
	}
}



/*********************************************************************
** Description: The review function can be accessed from the main game 
** menu, and it prints out the player's current location, map, and notes.
*********************************************************************/ 
void Game::review()
{
	printMap();
	cout << "You are in the " << milosh.getLocation()->getName() << "." << endl << endl << endl;
	pressEnter();
	
	clearScreen(8);
	printNotes();
	pressEnter();
}



/*********************************************************************
** Description: The takeAction function receives a char parameter 
** indicating the player's menu choice, and it routes control to the 
** appropriate function for the player to enact. 
*********************************************************************/ 
void Game::takeAction(char userChoice) 
{
	switch (userChoice)
	{
		case 'L': printMap();
				  milosh.travel();
				  break;
		case 'I': milosh.removeFromSack();
				  break;
		case 'R': review();
				  break;
		case 'B': milosh.barter();
				  break;
		case 'T': milosh.talk();
				  break;
		case 'P': milosh.plough();
				  break;
		case 'S': milosh.search();
				  break;
		case 'E': milosh.eat();
				  break;
		case 'V': milosh.vodka();
				  break;
		case 'C': milosh.confront();
				  break;
	}
}



/*********************************************************************
** Description: The won function checks the player's boolean getWon()
** to see if the player won
*********************************************************************/ 
bool Game::won()
{
	return milosh.getWon();
}



/*********************************************************************
** Description: The starved function checks the corresponding function
** in player to see if the player ran out of potatoes.
*********************************************************************/ 
bool Game::starved()
{
	return milosh.getStarved();
}



/*********************************************************************
** Description: Default empty destructor
*********************************************************************/ 
Game::~Game()
{
	//
}


