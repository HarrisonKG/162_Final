/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final. 
** This is the header file for input validation functions. The primary 
** functions useful to outside programs are getInt(), getString(), 
** validateChar(), and getDouble(), as well as menuChoice() which returns 
** user's integer choice from a list. The other functions 
** are helper functions.
*********************************************************************/
#ifndef VALIDATE_INPUT_HPP
#define VALIDATE_INPUT_HPP

#include <string>


int menuChoice();
void clearScreen(int lines = 50);
void pressEnter(std::string s = "[Press enter to continue]"); 
void pause(int x); 

std::string getString();
bool isString(std::string testString);

char validateChar(std::string letters);
char getChar();

double getDouble(double min, double max);
bool isDouble(std::string testString);
bool validDoubleRange(std::string testString, double min, double max);

int getInt(int min, int max);
bool isInteger(std::string testString);
bool validIntRange(std::string testString, int min, int max);


#endif