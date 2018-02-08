/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the main file for Final. After unzipping the compressed folder, 
** run make to compile, then run "./Final". You can also run make memcheck
** to check memory, or make clean to remove .o and the executable file. 
*********************************************************************/ 
#include "Game.hpp"




int main()
{
	Game game = Game();
	game.playGame();

	return 0;
}