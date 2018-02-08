/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final Project
** This is the implementation file for the Player class. Player function
** descriptions are detailed below.
*********************************************************************/ 
#include "Player.hpp"
#include "Market.hpp"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
using std::string;
using std::cout;
using std::cin;
using std::endl;



/*********************************************************************
** Description: The Player constructor initializes the potato count 
** and adds some essentials to the sack.
*********************************************************************/ 
Player::Player()
{
	potatoes = 100;
	sack.push_back("potatoes");
	sack.push_back("towel");
	sack.push_back("spoon");

	// seed random generator
	srand(time(0));
	
}



/*********************************************************************
** Description: The travel function indicates the player's current location
** and prints out the corresponding menu indicating possible directions
** to choose. Location is updated after the direction is chosen.
*********************************************************************/ 
void Player::travel()
{
	cout << "You are in the " << location->getName() << "." << endl << endl << endl;
	char dir = location->travelMenu();

	switch (dir)
	{
		case 'N': setLocation(location->getNorth());
				break;
		case 'E': setLocation(location->getEast());
				break;
		case 'S': setLocation(location->getSouth());
				break;
		case 'W': setLocation(location->getWest());
				break;
	}
	cout << "\nTraveling to " << location->getName() << "...." << endl << endl;
	pause(1200);
}



/*********************************************************************
** Description: The barter function details a trade exchange with a 
** merchant character. Items can be bought if you have enough potatoes. 
** If your sack is too full, you'll be prompted to remove something 
** in the addSack function first before you can take the new thing with you.
*********************************************************************/ 
void Player::barter() 
{
	clearScreen();
	cout << "Merchant: \n\nGood day! I am pleased to be making your acquaintance!" << endl << endl;
	cout << "I have many elegant wares, and for you, an impeccable price." << endl;
	clearScreen(8);
	cout << "What will be your purchase today?" << endl << endl << endl;
	
	static_cast<Market*>(location)->printWares();
	int newItem = getInt(0, 5);


	// vector has 5 items, 0 is "nevermind" option
	while (newItem > 0) 
	{
		int price = static_cast<Market*>(location)->getCost(newItem);
		string name = static_cast<Market*>(location)->getName(newItem);
		
		clearScreen();
		cout << "You have " << potatoes << " potatoes, and the " << name
			 << " is costing.. " << price << " potatoes." << endl << endl << endl << endl;


		// check that have enough potatoes
		if (price > potatoes)
		{
			cout << "Merchant: \nHa! You do not have nearly enough potatoes." << endl << endl << endl;
			cout << "You are excellent negotiator, but the merchant is in no mood for jokes." << endl;
			clearScreen(5);
		}
		else if (price > potatoes - 5)
		{
			cout << "But this will be leaving you with only " << potatoes - price << " potatoes!" << endl << endl << endl;
			cout << "The merchant will not allow you be so irresponsible with your potatoes and starve." << endl << endl << endl;
			cout << "Come back when you have at least " << price + 5 << " potatoes." << endl;
			clearScreen(5);
		}
		else
		{
			bool added = addToSack(name);

			if (added)
			{
				cout << "\n\nYou are pleased with your new purchase of " << name << "!" << endl << endl << endl;
				setPotatoes(0 - price);
			}
		}

		cout << "\nWill you be having something else?" << endl << endl;
		static_cast<Market*>(location)->printWares();
		newItem = getInt(0, 5);
	}
}



/*********************************************************************
** Description: The talk function can be chosen in the market or tavern 
** spaces. Shopkeepers help to point your way to the Babushka, and the 
** Babushka gives advice on how to rid a village of a bear. 
*********************************************************************/ 
void Player::talk()
{
	clearScreen();

	if(location->getName() == "village market")
	{
		cout << "Shopkeeper: " << endl << endl << endl;
		cout << "Yes, we have been having such an inundation of bear malfeasance." << endl << endl; 
		cout << "I think you must travel to the next village to seek advice." << endl << endl;
		cout << "Our neighbors once endured bear juggernaut of their own, "
			 << "but now, somehow, the bears are not daring to go there." << endl;
		clearScreen(8);
		pressEnter();	
	}
	else if (location->getName() == "neighboring village market")
	{
		cout << "Oh, you must be seeking the Babushka!" << endl << endl << endl;
		cout << "I think you will be finding her in the vodka-tavern." << endl;
		clearScreen(8);
		pressEnter();
	}
	else if (location->getName() == "tavern")
	{
		cout << "Babushka:" << endl << endl;
		cout << "Ah, Milosh, it is good to be seeing you again." << endl << endl;
		cout << "I hear you are having some bear delinquency in your village. " << endl;
		clearScreen(5);
		pause(3000);
		
		cout << "Yes, we discovered a solution some years ago.." << endl << endl;
		cout << "The Babushka scribbles out a note, and slides it across to you." << endl << endl;
		pressEnter();

		cout << "The Babushka explains -- " << endl << endl;
		cout << "There is a Swedish instrument of music, a nyckelharpa, "
			 << "which affects a bear most tremendously." << endl << endl; 
		pause(3000);
		cout << "You see, such miscreants are not from these lands. They come from the West, " 
			 << "and if you play to them the melodies of their ancestral homelands, " << endl;
		cout << "they cannot help but be called back to their old country." << endl << endl;
		pause(3000);
		cout << "You must get a NYCKELHARPA." << endl << endl << endl;
		cout << "Take the note? Y/n" << endl << endl;
		char note = validateChar("YN");

		if (note == 'Y')
		{
			addToSack("\"get a nyckelharpa\"");
		} 
	}
}



/*********************************************************************
** Description: The search function can be chosen in the Hut, and it 
** delivers seed spuds to you, which are needed before you can plough. 
*********************************************************************/ 
void Player::search()
{
	clearScreen();
	cout << "Inside hut you see a bounteous pile of seed spuds." << endl << endl << endl;
	cout << "Your heirloom spuds are reknowned throughout the valley " 
		 << "for their nutritious and prodigious nature." << endl;
	clearScreen(8);
	cout << "Take them with you? Y/N" << endl << endl;
	char spudResponse = validateChar("YN");

	if (spudResponse == 'Y')
	{
		cout << "\n\nYou add them to your sack." << endl << endl;
		addToSack("seed spuds");
		pause(2000);
	}
}



/*********************************************************************
** Description: The eat function does not help you in your quest, but it 
** lets you enjoy a tasty potato.
*********************************************************************/ 
void Player::eat()
{
	clearScreen();
	cout << "You are savoring one especially delicious starchy tuber." << endl << endl << endl;
	cout << "You are happy in this moment." << endl;
	clearScreen(8);

	setPotatoes(-1);
	pressEnter();
}



/*********************************************************************
** Description: The plough function can be chosen in a Field, and it is
** necessary before the game can be won, because you will need more 
** potatoes than you start off with. 
*********************************************************************/ 
void Player::plough() 
{
	clearScreen();
	int potatoesGained = 0;

	if (armed("seed spuds"))
	{
		cout << "You are toiling in fields for many hours with loyal plough-donkey." << endl;
		clearScreen(5);

		if(location->getName() == "potato field of dreams")
		{
			cout << "Your efforts are rewarded with 20 potatoes." << endl;
			potatoesGained = 20;
		}
		else if (location->getName() == "stingy potato field")
		{
			cout << "Your efforts are rewarded with 5 potatoes." << endl;
			potatoesGained = 5;
		}

		clearScreen(4);
		setPotatoes(potatoesGained);
		clearScreen(4);
	}
	else
	{
		cout << "You are not having seed spuds yet. You will need these in your sack first!" << endl << endl << endl;
		cout << "You think you may have left them in your hut for safekeeping..." << endl;
		clearScreen(8);
	}
	
	pressEnter();
}



/*********************************************************************
** Description: The vodka function does not help in your quest, but if
** you are in a Tavern and have potatoes to waste..
*********************************************************************/ 
void Player::vodka()
{
	clearScreen();
	cout << "You cherish a vodka now because everything will be gone soon." << endl;
	clearScreen(12);
	setPotatoes(-5);
	pressEnter();
}



/*********************************************************************
** Description: The confront function handles interaction with the bear. 
** You will win if you have the nyckelharpa, otherwise you will just
** lose potatoes until you quit or die. 
*********************************************************************/ 
void Player::confront() 
{
	clearScreen();

	// prepared
	if (armed("nyckelharpa"))
	{
		cout << "The lullaby tones of the nyckelharpa stirs in the bear "
			 << "a longing for its ancestral home in the fjords." << endl << endl << endl; 
		cout << "The music of its childhood sends it lolloping over the mountains to search for its kin. " << endl;
		clearScreen(5);
		cout << "The bear is vanquished!!" << endl;
		clearScreen(15);
		pressEnter();

		won = true;
	}
	// a losing battle
	else 
	{
		char fightDecision;
		do 
		{
			clearScreen();
			cout << "You subject bear to onslaught of pelted potatoes!" << endl << endl;
			cout << "but now you have lost 10 potatoes and bear is unimpressed." << endl << endl << endl;
			setPotatoes(-10);

			if (!starved)
			{
				clearScreen(5);
				cout << "The situation is appearing dire. Continue fighting bear?" << endl << endl;
				cout << "Press Y for continuing the fight, or N to reconsider other valiant options." << endl << endl;
				fightDecision = validateChar("YN");
			}
			else 
			{
				// dead
				fightDecision = 'N';
			}
		} while (fightDecision == 'Y');
	}
}



/*********************************************************************
** Description: The addToSack function adds a new item to your sack, 
** and if it is too full already (max capacity is 6), and you will be 
** prompted to remove items.
*********************************************************************/ 
bool Player::addToSack(string item) 
{
	bool added = false;

	// sack capacity is 6
	if (sack.size() == sack_max)
	{
		cout << "Your sack is already too full of treasures!" << endl << endl;
		cout << "You must leave a thing behind, to be adding in something more." << endl << endl;
		removeFromSack();
	}

	if (sack.size() < sack_max) 
	{	
		sack.push_back(item);
		added = true;
	}

	return added;
}



/*********************************************************************
** Description: The removeFromSack function is called if your sack is
** too full to add a newly acquired item, or you check the inventory 
** during gameplay. It loops until you decide to not remove anything. 
*********************************************************************/ 
void Player::removeFromSack() 
{
	unsigned int itemToAbandon = 1;

	// keeps removing until user says 'never mind'
	while (itemToAbandon > 0) 
	{
		cout << "\nWhat will you be leaving by the wayside?" << endl << endl << endl;
		cout << "0: " << "Never mind now, keep all of the things." << endl;
		cout << "Contents of sack:" << endl;

		for (unsigned int i = 0; i < sack.size(); i++)
		{
			cout << i + 1 << ": " << sack[i];

			if(sack[i] == "potatoes")
			{
				cout << "(" << potatoes << ")";
			}
			cout << endl;
		}

		itemToAbandon = getInt(0, sack.size());

		if (itemToAbandon > 0)
		{
			if (sack[itemToAbandon - 1] == "potatoes")
			{
				clearScreen(8);
				cout << "You had better keep these." << endl;
				clearScreen(8);
			}
			else
			{
				cout << "\n\n\nTossing out the " << sack[itemToAbandon - 1] 
					 << "..." << endl << endl << endl << endl;
				sack.erase(sack.begin() + itemToAbandon - 1);
			}
		}
	}
}



/*********************************************************************
** Description: The armed function returns a bool indicated whether
** you have that item (string sent as a parameter) in your sack.
*********************************************************************/ 
bool Player::armed(string item)
{
	bool armed = false;

	for (unsigned int i = 0; i < sack.size(); i++)
	{		
		if (sack[i] == item)
		{
			armed = true;
		}
	}
	return armed;
}




/*********************************************************************
** Description: The chanceOfAttack function calculates a random number 
** and assesses the possibility of the bear attack. If you're in field_1 
** or market_1, there is a ~14% chance of being attacked during any action
** taken.  
*********************************************************************/ 
void Player::chanceOfAttack() 
{
	if ((location->getName() == "potato field of dreams" || location->getName() == "village market")
		&& !armed("nyckelharpa"))
	{
		int threat = rand() % 7;

		if (threat == 6)
		{
			pause(500);
			clearScreen(5);

			cout << "The bear has made a rampage through the " << location->getName() 
				 << "!!" << endl << endl;
			pause(2000);
			
			cout << "You have ousted the pestilence with well-aimed potato grenades, " 
			 << "but now you have 10 fewer in your sack." << endl << endl;
			pause(2000);

			setPotatoes(-10);
			pressEnter();
		}
	}
}



/*********************************************************************
** Description: The chanceOfHunger function calculates a number between
** 2 and 23, and if it is less than 6, the player needs a snack. This gives
** about a 19% chance that the player will need a meal, each being 
** between 2 and 5 potatoes.
*********************************************************************/ 
void Player::chanceOfHunger()
{
	int chance = rand() % 22 + 2;

	if (chance < 4)
	{
		pause(500);
		cout << "\n\nYou are feeling very peckish so you make a small meal of " 
			 << chance << " potatoes." << endl << endl;
		pause(1000);
		setPotatoes(0 - chance);
		pressEnter();

	}
	else if (chance < 6)
	{	
		pause(1000);
		cout << "\n\nYou realize you are famished! " << chance << " potato snacks later..." << endl << endl;
		pause(1000);
		setPotatoes(0 - chance);
		pressEnter();
	}
}



/*********************************************************************
** Description: The potatoWarnings function monitors your potato levels, 
** and outputs warnings as needed, or gives a normal potato count update. 
*********************************************************************/ 
void Player::potatoWarnings()
{
	
	if (potatoes < 1)
	{
		cout << "\n\nYou have lost your last potato! You can feel the darkness creeping in..." << endl;
		clearScreen(5);
		pause(3000);		
		starved = true;
	}
	else if (potatoes < 15 && ! secondWarning)
	{
		cout << "\n\nYou have only " << potatoes << " potatoes remaining!!" << endl << endl;
		cout << "Be careful not to waste precious potatoes or you will perish!" << endl << endl;
		secondWarning = true;
	}
	else if (potatoes < 25 && !firstWarning)
	{
		cout << "\n\nYour sack is beginning to feel unusually light." << endl << endl; 
		cout << "You now have only " << potatoes << " potatoes!" << endl << endl;
		firstWarning = true;
	}
	else
	{
		cout << "You have still " << potatoes << " potatoes remaining." << endl << endl << endl;
	}
}



/*********************************************************************
** Description: Accessor function for number of potatoes remaining
*********************************************************************/ 
int Player::getPotatoes()
{
	return potatoes;
}



/*********************************************************************
** Description: Accessor function for current location
*********************************************************************/ 
Space* Player::getLocation()
{
	return location;
}



/*********************************************************************
** Description: Accessor function for win status
*********************************************************************/
bool Player::getWon()
{
	return won;
}



/*********************************************************************
** Description: Accessor function for alive/dead status
*********************************************************************/
bool Player::getStarved()
{
	return starved;
}




/*********************************************************************
** Description: Mutator function for potato counter. Accepts as an int
** parameter the + or - amount of potatoes gained or lost, and updates it.
*********************************************************************/
void Player::setPotatoes(int gainOrLoss)
{
	potatoes += gainOrLoss; 

	if (gainOrLoss < 0)
	{
		potatoWarnings();
	}
	else 
	{
		cout << "You have now " << potatoes  << " potatoes." << endl << endl;
	}
}



/*********************************************************************
** Description: Mutator function for current location. Accepts as a
** Space pointer parameter the space to move to, and updates location.
*********************************************************************/
void Player::setLocation(Space* newSpace)
{
	location = newSpace;
}



/*********************************************************************
** Description: Destructor sets location pointer to null
*********************************************************************/
Player::~Player()
{
	location = nullptr;
}
