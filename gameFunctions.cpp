
#include <iostream>
#include <string>
#include <algorithm>

/***************************************************************
 * Function Name: bool keepPlaying
 * Parameters: N/A
 * Description: Asks user if they would like to keep playing.
***************************************************************/

bool keepPlaying()
{
	std::string answer = "";
	bool invalid = true;

	while(invalid)
	{
		std::cout << "Would you like to keep playing? y/n? ";
		std::getline(std::cin, answer);

		if (answer.length() > 1)
			std::cout << "Please enter y or n." << std::endl;
		else if (tolower(answer[0]) == 'y')
		{	return true; invalid = false;}
		else if (tolower(answer[0]) == 'n')
		{	std::cout << "Goodbye!" << std::endl; return false; invalid = false;}
		else
			std::cout << "Please enter y or n." << std::endl;
	}
	return false;
}

/***************************************************************
 * Function Name: bool isInteger
 * Parameters: std::string
 * Description: Returns false string is empty, returns true if
 * 		string length is 1 and the first char of string
 * 		is a digit, returns false if first char of 
 * 		string is - and the second char is not a digit,
 * 		and checks if the rest of the string is a digit.
 * Source: Phi Luu
***************************************************************/

bool isInteger(std::string s)
{
	if (s.empty())
		return false;

	if (s.length() == 1 && isdigit(s[0]))
		return true;

	if (s[0] != '-' && !isdigit(s[0]))
		return false;

	return (std::all_of(s.begin() + 1, s.end(), ::isdigit));
}


/***************************************************************
 * Function Name: void valNum 
 * Parameters: &num
 * Description: Asks the user for number of animals while not 1
 * 		or 2.
***************************************************************/
void valNum(std::string &num)
{
	bool numInvalid = true;
	while (numInvalid)
	{
		std::getline(std::cin, num); 
		
		if (isInteger(num))
		{
			if (std::stoi(num) == 2 || stoi(num) == 1)
			{	numInvalid = false;}
			else
				std::cout << "Please enter 1 or 2." << std::endl;
		}
		else
			std::cout << "Please enter 1 or 2." << std::endl;
	}
}

/***************************************************************
 * Function Name: void clearScreen
 * Parameters: None
 * Description: Clears screen by inserting 100 lines.
***************************************************************/

void clearScreen()
{
	std::cout << std::string(100, '\n');
}

