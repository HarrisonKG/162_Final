/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the Market class. It defines the 
** pure virtual functions that it inherits from Space, and also contains
** a vector storing items that can be bought at the market space. 
*********************************************************************/ 
#include "Market.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;



/*********************************************************************
** Description: The Market constructor creates a vector full of "Wares" 
** structs, which bundle together a name, description, and price for 
** items that can be bought at the market.
*********************************************************************/
Market::Market(string name) : Space(name)
{


	string beans = "Beans (costing 2 potatoes)";
	string pot = "Dzezva pot for making delicious coffee (8 potatoes)";
	string hut = "Luxury real estate, 2-story hut in best neighborhood (600 potatoes)";
	string instrument = "Genuine Swedish nyckelharpa (100 potatoes)";
	string plough = "Top-of-the-line potato plough, only slightly used (200 potatoes)";

	Wares beanItem = Wares(beans, "beans", 2); 
	Wares potItem = Wares(pot, "dzezva pot", 8); 
	Wares hutItem = Wares(hut, "luxe hut", 600); 
	Wares instrumentItem = Wares(instrument, "nyckelharpa", 100);
	Wares ploughItem = Wares(plough, "plough", 200);

	marketWares = {beanItem, potItem, hutItem, instrumentItem, ploughItem};
}



/*********************************************************************
** Description: The Wares constructor defines the struct as consisting
** of 2 strings (description and name) and int price.
*********************************************************************/
Market::Wares::Wares(string d, string n, int c)
{
	description = d;
	name = n;
	cost = c;
}



/*********************************************************************
** Description: The areaInfo function prints out a location tag
*********************************************************************/
void Market::areaInfo()
{
	if(name == "village market")
	{
		cout << "You are in the marketplace of your village." << endl << endl;
	}
	else if (name == "neighboring village market")
	{
		cout << "You are in the marketplace of neighboring village." << endl << endl;
	}
}



/*********************************************************************
** Description: The menu function prints out the options available and 
** returns the char chosen.
*********************************************************************/
char Market::menu()
{
	cout << "What is your wish? Please enter a letter:" << endl;
	cout << "T - Talk to merchant" << endl;
	cout << "B - Barter" << endl;
	cout << "L - Leave market" << endl;
	cout << "I - Inventory the potato sack" << endl;
	cout << "R - Review map and notes" << endl;
	cout << "X - Exit game" << endl;

	string market_chars = "TBLIRX";
	char answer = validateChar(market_chars);

	return answer;
}



/*********************************************************************
** Description: The displaySpace function opens and prints out the txt
** file depicting the location.
*********************************************************************/
void Market::displaySpace()
{
	string filename;

	if (name == "village market")
	{
		filename = "market.txt";
	}
	else if (name == "neighboring village market")
	{
		filename = "neighbor_market.txt";
	}

	std::ifstream inputFile;
	inputFile.open(filename);

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
		cout << "Error opening file." << endl;
	}
}




/*********************************************************************
** Description: The printWares function prints out the options for sale.
*********************************************************************/
void Market::printWares()
{
	cout << "0: (Thank you, I am not needing anything now)" << endl;

	for(unsigned int i = 0; i < marketWares.size(); i++)
	{
		cout << i + 1 << ": " << marketWares[i].description << endl;
	}
}



/*********************************************************************
** Description: Returns the price of an item identified by list number
*********************************************************************/
int Market::getCost(int itemNumber)
{
	int price = marketWares[itemNumber-1].cost;
	return price;
}



/*********************************************************************
** Description: Returns the name of an int identified by list number
*********************************************************************/
string Market::getName(int itemNumber)
{
	string name = marketWares[itemNumber-1].name;
	return name;
}



/*********************************************************************
** Description: Empty virtual destructor
*********************************************************************/
Market::~Market()
{
	//
}

