/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Main file for Zoo Tycoon project.
***************************************************************/
#include "Animal.hpp"
#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "gameFunctions.hpp"

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string tigersToStart, penguinsToStart, turtlesToStart;
	clearScreen();
	std::cout << "::ZOO TYCOON::\n" << std::endl;
	std::cout << "Welcome to Zoo Tycoon!\n" << std::endl;
	std::cout << "You have $100,000 in the bank to buy animals and their food." << std::endl;
	std::cout << "Tigers cost $10,000 and $50 per day to feed, have 1 baby, and payoff $2000 per day." << std::endl;
	std::cout << "Penguins cost $1,000 and $10 per day to feed, have 5 babies, and payoff $100 per day." << std::endl;
	std::cout << "Turtles cost $100 and $5 per day to feed, have 10 babies, and payoff $5 per day." << std::endl;
	std::cout << std::endl;
	std::cout << "Please select 1 or 2 of each animal to play." << std::endl;
	std::cout << "Tigers: ";
	valNum(tigersToStart);
	std::cout << "Penguins: ";
	valNum(penguinsToStart);
	std::cout << "Turtles: ";
	valNum(turtlesToStart);
	std::cout << std::endl;
	
	Zoo zoo(std::stoi(tigersToStart), std::stoi(penguinsToStart), std::stoi(turtlesToStart));
	
	int day = 0;
	do
	{
		std::cout << std::endl;
		//clearScreen();
		std::cout << "Day " << ++day << std::endl;
	
		zoo.day();

		if (zoo.getMoney() <= 0)
		{
			std::cout << "You are out of money. GAME OVER." << std::endl;
			return 0;
		}
		
	} while (keepPlaying());

	return 0;
}


