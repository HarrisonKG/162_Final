/********************************************************************* 
** Program name: Final
** Author: Kristen Harrison
** Date: 16 August 2017
** Description: CS 162, Final. This is the implementation file for 
** reusable input validation and menu functions. The string library is  
** included through the header file. Individual function descriptions below.
*********************************************************************/ 
#include "validateInput.hpp"
#include <iostream>
#include <chrono>
#include <thread>
using std::string;
using std::cout;
using std::endl;
using std::cin;




/*********************************************************************
** Description: The menuChoice function can be customized to print out
** listed options. It uses getInt to validate user input before returning
** that response as an int. 
*********************************************************************/ 
int menuChoice()
{
	cout << "\nEnter the number of your selection:\n"
		 << "1. Play game\n"
		 << "2. Exit" << endl;
	
	int menuItem = getInt(1, 2);
	return menuItem;
}



/*********************************************************************
** Description: The clearScreen function prints out endlines to the 
** console. Designating an int parameter is optional; default is 50.
*********************************************************************/ 
void clearScreen(int lines)
{
	for (int i = 0; i < lines; i++)
	{
		cout << endl;
	}
}



/*********************************************************************
** Description: The pressEnter function prints out a prompt for the user
** to press a key; program resumes when the user does so. The prompt can
** be sent as a string parameter; the default is [Press enter to continue].
*********************************************************************/ 
void pressEnter(string prompt)
{
	cout << prompt << endl << endl << endl;
	string s;
	std::getline(cin, s);
}



/*********************************************************************
** Description: The pause function takes an int parameter, and sleeps
** for that many milliseconds.
*********************************************************************/ 
void pause(int x)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
}



/*********************************************************************
** Description: The getString function requests a string from the user, 
** then tests whether the string is comprised of only alphabetic and 
** space characters before the returning the string
*********************************************************************/ 
string getString()
{
	string testString;
	std::getline(cin, testString);
	
	while (!isString(testString) || testString.length() > 20)
	{
		cout << "Invalid input, please enter an alphabetic string " 
			 << "up to 20 letters in length." << endl;
		std::getline(cin, testString);
	}

	return testString;
}



/*********************************************************************
** Description: The isString function takes a single string parameter,
** and it returns true if the string is comprised of only alphabetic
** chars and spaces, and false otherwise. 
*********************************************************************/
bool isString(string testString)
{
	bool validString = true;

	// all chars in string must be alphabetic or a space
	for (unsigned int i = 0; i < testString.length(); i++)
	{
		if (!isalpha(testString[i]) && (testString[i] != ' '))
		{
			validString = false;
		}
	}

	return validString;
}



/*********************************************************************
** Description: The validateChar function validates a char input to 
** be a single letter that is contained within the string parameter
** of acceptable char inputs.
*********************************************************************/ 
char validateChar(string letters)
{
	char str_char = getChar();
    str_char = toupper(str_char);
    bool validChar = false;

    for (unsigned int i = 0; i < letters.length(); i++)
    {
    	if (letters[i] == str_char)
    	{
    		validChar = true;
    	}
    }

	while (!validChar)
	{
        cout << "\nInvalid input. Please enter one of these options:" << endl;
        
        for(unsigned int i = 0; i < letters.length(); i++)
        {
        	cout << "\'" << letters[i] << "\'" << endl;
        }

        str_char = getChar();
        str_char = toupper(str_char);

        for (unsigned int i = 0; i < letters.length(); i++)
	    {
	    	if (letters[i] == str_char)
	    	{
	    		validChar = true;
	    	}
	    }
    } 

    return str_char;
}



/*********************************************************************
** Description: The getChar function requests input, stores it as a  
** string, tests if the first char is valid, then returns the response.
*********************************************************************/ 
char getChar()
{
	string testString;
	std::getline(cin, testString);

	char firstChar = testString[0];
		
	while (!firstChar || testString.length() > 1)
	{
		cout << "Invalid input, please enter a char" << endl;
		std::getline(cin, testString);
		firstChar = testString[0];
	}
	
	return firstChar;
}



/*********************************************************************
** Description: The getDouble function takes two parameters: the min and 
** max of the acceptable range of double values. The function takes cin 
** input as a string then validates it with validDoubleRange before  
** returning the user response as a double.
*********************************************************************/ 
double getDouble(double min, double max)
{	
	string testString;
	std::getline(cin, testString);

	while (!validDoubleRange(testString, min, max))
	{
		cout << "Invalid input, please enter a double between " 
			 << min << " and " << max << endl;
		std::getline(cin, testString);
	}

	double doubleInput = std::stod(testString);
	return doubleInput;
}



/*********************************************************************
** Description: The isDouble function takes a single string parameter,
** and it returns true if the string represents a double (if the string 
** is not empty and every char is a digit or a decimal point, with no
** more than 1 decimal point.  
*********************************************************************/
bool isDouble(string testString)
{
	int decimals = 0;
	bool validDouble = true;

	for (unsigned int i = 0; i < testString.length(); i++)
	{
		// not a double if every character is neither digit nor point
		if (!isdigit(testString[i]) && testString[i] != '.')
		{
			validDouble = false;
		}

		// keep track of decimal points
		if (testString[i] == '.')
		{
			decimals++;
		}
	}

	if (decimals > 1 || testString.empty() || testString == ".")
	{
		validDouble = false;
	}

	return validDouble;
}



/*********************************************************************
** Description: The validDoubleRange function takes as its parameters a 
** string and double min and max values. It returns true if the string 
** represents a double within the min/max range, and false otherwise.
*********************************************************************/ 
bool validDoubleRange(string testString, double min, double max)
{
	bool validRange = false;

	if (isDouble(testString))
	{
		double doubleInput = std::stod(testString);

		if ((doubleInput >= min) && (doubleInput <= max))
		{
			validRange = true;
		}
	}

	return validRange;
}



/*********************************************************************
** Description: The getInt function takes two parameters: the min and 
** max of the acceptable range of int values. The function takes cin 
** input as a string then validates it with validIntRange before  
** returning the user response as an integer.
*********************************************************************/ 
int getInt(int min, int max)
{
	string testString;

	// store input as string and check validity
	std::getline(cin, testString);

	while (!validIntRange(testString, min, max))
	{
		cout << "Invalid input, please enter an integer between "
			 << min << " and " << max << endl;
		std::getline(cin, testString);
	}

	int input = std::stoi(testString);	
	return input;
}



/*********************************************************************
** Description: The isInteger function takes a single string parameter,
** and it returns true if the string represents an int (if the string 
** is not empty and every char, except the first if it is a minus sign, 
** is a digit), and returns false otherwise.  
*********************************************************************/ 
bool isInteger(string testString)
{
	bool validInt = true;

	if (testString.empty())
	{
		validInt = false;
	}

	// allows negative ints by checking first digit for minus sign
	if ((!isdigit(testString[0]) && testString[0] != '-') || 
		(testString[0] == '-' && testString.length() < 2))
	{
		validInt = false;
	}

	// all other chars in string must be digits
	for (unsigned int i = 1; i < testString.length(); i++)
	{
		if (!isdigit(testString[i]))
		{
			validInt = false;
		}
	}

	return validInt;
}



/*********************************************************************
** Description: The validIntRange function takes as its parameters a 
** string and integer min and max values. It returns true if the string 
** represents an integer within the min/max range, and false otherwise.
*********************************************************************/ 
bool validIntRange(string testString, int min, int max)
{
	bool validRange = false;

	if (isInteger(testString))
	{
		int intInput = std::stoi(testString);

		if ((intInput >= min) && (intInput <= max))
		{
			validRange = true;
		}
	}

	return validRange;
}



