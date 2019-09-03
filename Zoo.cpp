/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Implementation file for Zoo class.
***************************************************************/
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "gameFunctions.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>

//Constructors
Zoo::Zoo()
{
	tigers = nullptr;
	penguins = nullptr;
	turtles = nullptr;
	money = 100000.0;

	numTigers = 0;
	numPenguins = 0;
	numTurtles = 0;

	capTigers = 10;
	capPenguins = 10;
	capTurtles = 10;
}

Zoo::Zoo(int tigersToStart, int penguinsToStart, int turtlesToStart)
{
	//Initialize variables
	//Initial size of array is 10
	capTigers = 10;
	capPenguins = 10;
	capTurtles = 10;

	//Numbers of each animal
	numTigers = tigersToStart;
	numPenguins = penguinsToStart;
	numTurtles = turtlesToStart;

	//Dynamic memory allocated for arrays of pointers to each object type
	tigers = new Tiger*[capTigers];
	penguins = new Penguin*[capPenguins];
	turtles = new Turtle*[capTurtles];
	
	//Set pointers to null
	for (int i = 0; i < 10; ++i)
	{
		tigers[i] = nullptr;
		penguins[i] = nullptr;
		turtles[i] = nullptr;
	}

	//Money in the bank starts at $100k
	money = 100000.0;
	
	//Seed random number generator
	srand(time(NULL));

	//Add animal to array and subtract cost
	double tigerTotal = 0.0, 
		penguinTotal = 0.0, 
		turtleTotal = 0.0;

	for (int i = 0; i < numTigers; ++i)
	{
		//Dynamic Tiger object created for each position in array
		tigers[i] = new Tiger;
		//Cost of each tiger subtracted from money in bank
		money -= tigers[i]->getCost();
		tigerTotal += tigers[i]->getCost();
	}
	std::cout << "You bought " << numTigers << " tigers for $" << tigerTotal << std::endl;
	for (int i = 0; i < numPenguins; ++i)
	{
		//Dynamic Tiger object created for each position in array
		penguins[i] = new Penguin;
		//Cost of each tiger subtracted from money in bank
		money -= penguins[i]->getCost();
		penguinTotal += penguins[i]->getCost();
	}
	std::cout << "You bought " << numPenguins << " penguins for $" << penguinTotal << std::endl;
	for (int i = 0; i < numTurtles; ++i)
	{
		//Dynamic Tiger object created for each position in array
		turtles[i] = new Turtle;
		//Cost of each tiger subtracted from money in bank
		money -= turtles[i]->getCost();
		turtleTotal += turtles[i]->getCost();
	}	
	std::cout << "You bought " << numTurtles << " turtles for $" << turtleTotal << std::endl;

	std::cout << "\nMoney in bank: $" << money << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.ignore();
}

//Destructor
Zoo::~Zoo()
{
	//Remove tigers from array
	for (int i = 0; i < numTigers; ++i)
	{
		delete tigers[i];
		tigers[i] = nullptr;
	}
	delete [] tigers;
	tigers = nullptr;

	//Remove penguins from array
	for (int i = 0; i < numPenguins; ++i)
	{
		delete penguins[i];
		penguins[i] = nullptr;
	}
	delete [] penguins;
	penguins = nullptr;

	//Remove turtles from array
	for (int i = 0; i < numTurtles; ++i)
	{
		delete turtles[i];
		turtles[i] = nullptr;
	}
	delete [] turtles;
	turtles = nullptr;
}

//Getters
double Zoo::getMoney()
{ return money; }

//Methods
/***************************************************************
 * Function Name: void day()
 * Parameters: N/A
 * Description: All events that happen in one day at the zoo.
***************************************************************/

void Zoo::day()
{
	double totalFoodCost = 0.0;

	//Calculates total number of animals	
	std::cout << std::endl;
	std::cout << "There are " << numTigers + numPenguins + numTurtles << " total animals in the zoo." << std::endl;

	//All animals age by one day and feeding cost paid for each
	//Tigers
	std::cout << std::endl;
	std::cout << "There are " << numTigers << " total tigers." << std::endl;	

	for (int i = 0; i < numTigers; ++i)
	{
		tigers[i]->getOlder();
		std::cout << "Tiger " << i + 1 << " is " << tigers[i]->getAge() << " days old." << std::endl;
		money -= tigers[i]->getFoodCost();
		totalFoodCost += tigers[i]->getFoodCost();
	}

	//Penguins	
	std::cout << std::endl;
	std::cout << "There are " << numPenguins << " total penguins." << std::endl;
	for (int i = 0; i < numPenguins; ++i)
	{	
		penguins[i]->getOlder(); 
		std::cout << "Penguin " << i + 1 << " is " << penguins[i]->getAge() << " days old." << std::endl;
		money -= penguins[i]->getFoodCost();
		totalFoodCost += penguins[i]->getFoodCost();
	}

	//Turtles
	std::cout << std::endl;
	std::cout << "There are " << numTurtles << " total turtles." << std::endl;
	for (int i = 0; i < numTurtles; ++i)
	{	
		turtles[i]->getOlder(); 
		std::cout << "Turtle " << i + 1 << " is " << turtles[i]->getAge() << " days old." << std::endl;
		money -= turtles[i]->getFoodCost();	
		totalFoodCost += turtles[i]->getFoodCost();	
	}

	std::cout << std::endl;	
	
	//Randomized event
	double tempMoney = money;
	randomEvent();
	
	//Calculate profit
	for (int i = 0; i < numTigers; ++i)
		money += tigers[i]->getPayoff();

	for (int i = 0; i < numPenguins; ++i)
		money += penguins[i]->getPayoff();

	for (int i = 0; i < numTurtles; ++i)
		money += turtles[i]->getPayoff();
	
	std::cout << std::endl;	
	std::cout << "Total food cost was $" << totalFoodCost << "." << std::endl;
	std::cout << "The total payoff for the day was $" << (money - tempMoney) << "." << std::endl;
	std::cout << "Money remaining: $" << money << std::endl;
	
	std::cout << std::endl;

	//Buy adult animal? If yes, subtract cost and add to zoo.
	askToBuyAnimal();
}

/***************************************************************
 * Function Name: void randomEvent()
 * Parameters: N/A
 * Description: Selects random event.
***************************************************************/

void Zoo::randomEvent()
{
	int randomNum = 0;
	randomNum = (1 + (rand() % 4));

	std::cout << "Random event: ";
	switch(randomNum)
	{
		case 1: animalDies();
			break;
		case 2: tigerBonus();
			break;
		case 3: babyBorn();
			break;
		case 4: nothingHappens();
			break;
		default: std::cout << "Default" << std::endl;
	}
}


/***************************************************************
 * Function Name: void animalDies()
 * Parameters: N/A
 * Description: Selects an animal at random to die.
***************************************************************/

void Zoo::animalDies()
{
	int totalAnimals = numTigers + numPenguins + numTurtles;
	//Generates random animal between 0 and totalAnimals - 1
	int randomAnimal = 0 + (rand() % totalAnimals);

	if (randomAnimal < numTigers)
	{
		delete tigers[randomAnimal];
		for (int i = randomAnimal; i < numTigers; ++i)
		{
			tigers[i] = tigers[i + 1];
		}
		tigers[numTigers] = nullptr;
		--numTigers;
		std::cout << "My condolences, a tiger has died." << std::endl;
	}
	else if (randomAnimal < (numTigers + numPenguins))
	{
		delete penguins[randomAnimal - numTigers];
		for (int i = randomAnimal - numTigers; i < numPenguins; ++i)
		{
			penguins[i] = penguins[i + 1];
		}
		--numPenguins;
		penguins[numPenguins] = nullptr;
		std::cout << "My condolences, a penguin has died." << std::endl;
	}
	else if (randomAnimal < totalAnimals)
	{
		delete turtles[randomAnimal - numTigers - numPenguins];
		for (int i = randomAnimal - numTigers - numPenguins; i < numTurtles; ++i)
		{
			turtles[i] = turtles[i + 1];
		}
		--numTurtles;
		turtles[numTurtles] = nullptr;
		std::cout << "My condolences, a turtle has died." << std::endl;
	}
}


/***************************************************************
 * Function Name: void tigerBonus()
 * Parameters: N/A
 * Description: Generates random amount between $250-500 to be
 * 		awarded for each tiger in the zoo.
***************************************************************/

void Zoo::tigerBonus()
{
	double randomBonus = 250 + (rand() % (500 - 250 + 1));
	double totalBonus = (randomBonus * numTigers);

	money += totalBonus;
	std::cout << "Congrats! There was a boom in zoo attendance due to the new tiger show. You've earned $" << randomBonus << " for each of your " << numTigers << " tigers for a total of $" << totalBonus << " today." << std::endl;
}

/***************************************************************
 * Function Name: void babyBorn()
 * Parameters: N/A
 * Description: Selects random type of animal to have babies only
 * 		if there is at least one adult. 
***************************************************************/

void Zoo::babyBorn()
{
	int types[3] = {1, 2, 3}; 

	bool animalTooYoung = true;
	while (animalTooYoung)
	{
		int count = 0,
		randomType = 0 + (rand() % (2 - 0 + 1));

		if (types[randomType] == 1)
		{
			for (int i = 0; i < numTigers; ++i)
			{
				if (tigers[i]->getAge() >= 3)
					count++;
			}
			if (count >= 1)
			{
				addTiger(numTigers, 0);
				std::cout << "Congrats! A baby tiger was born." << std::endl;
				animalTooYoung = false;
			}
			else if (count == 0)
				types[0] = 0;
		}
		if (types[randomType] == 2)
		{
			for (int i = 0; i < numPenguins; ++i)
			{
				if (penguins[i]->getAge() >= 3)
					count++;
			}
			if (count >= 1)
			{
				for (int i = 0; i < 5; ++i)
				{
					addPenguin(numPenguins, 0);
				}
				std::cout << "Congrats! Five baby penguins were born." << std::endl;
				animalTooYoung = false;
			}
			else if (count == 0)
				types[1] = 0;
		}
		if (types[randomType] == 3)
		{
			for (int i = 0; i < numTurtles; ++i)
			{
				if (turtles[i]->getAge() >= 3)
					count++;
			}
			if (count >= 1)
			{
				for (int i = 0; i < 10; ++i)
				{
					addTurtle(numTurtles, 0);
				}
				std::cout << "Congrats! Ten baby turtles were born." << std::endl;
				animalTooYoung = false;
			}	
			else if (count == 0)
				types[2] = 0;
		}
		if (types[0] == 0 && types[1] == 0 && types[3] == 0)
		{
			std::cout << "All animals are too young to have children." << std::endl;
			animalTooYoung = false;
		}
	}	
}

/***************************************************************
 * Function Name: void nothingHappens()
 * Parameters: N/A
 * Description: Nothing happens.
***************************************************************/

void Zoo::nothingHappens()
{
	std::cout << "Sorry! Nothing happened." << std::endl;
}

/***************************************************************
 * Function Name: void buyAnimal()
 * Parameters: N/A
 * Description: Adds user's choice of new animal to zoo and
 * 		subtracts cost.
***************************************************************/

void Zoo::buyAnimal()
{
	std::string animal;	
	std::cout << "What type of animal would you like to buy? (1: tiger, 2: penguin, 3: turtle)" << std::endl;
	
	bool invalid = true;
	while(invalid)
	{
		std::cout << "Animal type: ";
		std::getline(std::cin, animal);
		
		if (isInteger(animal))
		{
			if (stoi(animal) == 1)
			{
				money -= 10000.0;
				addTiger(numTigers, 3);
				invalid = false;
			}
			else if (stoi(animal) == 2)
			{
				money -= 1000.0;
				addPenguin(numPenguins, 3);
				invalid = false;
			}
			else if (stoi(animal) == 3)
			{
				money -= 100.0;
				addTurtle(numTurtles, 3);
				invalid = false;
			}
		}
		else
			std::cout << "Please enter tiger, penguin, or turtle." << std::endl;
	}
}


/***************************************************************
 * Function Name: void askToBuyAnimal()
 * Parameters: N/A
 * Description: Asks user if they would like to buy an animal.
***************************************************************/

void Zoo::askToBuyAnimal()
{
	std::string answer;
	bool invalid = true;

	while(invalid)
	{
		std::cout << "Would you like to buy an adult animal? y/n? ";
		std::getline(std::cin, answer);

		if (answer.length() > 1)
			std::cout << "Please enter y or n." << std::endl;	
		else if (tolower(answer[0]) == 'y')
		{	buyAnimal(); invalid = false;}
		else if (tolower(answer[0]) == 'n')
		{	invalid = false;}
		else
			std::cout << "Please enter y or n." << std::endl;
	}
}


/***************************************************************
 * Function Name: void addTiger()
 * Parameters: int index, int age
 * Description: If the number of tigers is the same as the tiger
 * 		capacity, the tiger capacity is doubled, a temp
 * 		array is created at double the capacity, and the
 * 		tiger pointers are copied to temp array. The temp
 * 		array is then reassigned as tigers and a new
 * 		tiger is added. If the number of tigers is less
 * 		than the tiger capacity, a new tiger is added.
***************************************************************/
void Zoo::addTiger(int index, int age)
{
	if (numTigers == capTigers)
	{	
		//Double size of tiger capacity
		capTigers *= 2;
		
		//Create temporary with new size
		Tiger **tempTiger = new Tiger*[capTigers];

		for (int i = 0; i < capTigers; ++i)
		{
			tempTiger[i] = nullptr;
		}

		//Copy pointers from old array to temp array
		for (int i = 0; i < numTigers; ++i)
		{
			tempTiger[i] = tigers[i];
		}

		delete [] tigers;
		tigers = tempTiger;
		
		//Add new tiger
		tigers[index] = new Tiger;
		tigers[index]->setAge(age);
		++numTigers;
		
	}
	else
	{ 
		//Add new tiger
		tigers[index] = new Tiger;
		tigers[index]->setAge(age);
		++numTigers;
	}
		
}

/***************************************************************
 * Function Name: void addPenguin()
 * Parameters: int index, int age
 * Description: If the number of penguins is the same as the penguin
 * 		capacity, the penguin capacity is doubled, a temp
 * 		array is created at double the capacity, and the
 * 		penguin pointers are copied to temp array. The temp
 * 		array is then reassigned as penguins and a new
 * 		penguin is added. If the number of penguins is less
 * 		than the penguin capacity, a new penguin is added.
***************************************************************/
void Zoo::addPenguin(int index, int age)
{
	if (numPenguins == capPenguins)
	{
		capPenguins *= 2;
		
		Penguin **tempPenguin = new Penguin*[capPenguins];
		
		for (int i = 0; i < capPenguins; ++i)
		{
			tempPenguin[i] = nullptr;
		}

		for (int i = 0; i < numPenguins; ++i)
		{
			tempPenguin[i] = penguins[i];
		}

		delete [] penguins;
		penguins = tempPenguin;
		
		penguins[index] = new Penguin;
		penguins[index]->setAge(age);
		++numPenguins;
	}
	else
	{
		penguins[index] = new Penguin;
		penguins[index]->setAge(age);
		++numPenguins;
	}
}	
/***************************************************************
 * Function Name: void addPenguin()
 * Parameters: int index, int age
 * Description: If the number of penguins is the same as the penguin
 * 		capacity, the penguin capacity is doubled, a temp
 * 		array is created at double the capacity, and the
 * 		penguin pointers are copied to temp array. The temp
 * 		array is then reassigned as penguins and a new
 * 		penguin is added. If the number of penguins is less
 * 		than the penguin capacity, a new penguin is added.
***************************************************************/
void Zoo::addTurtle(int index, int age)
{
	if (numTurtles == capTurtles)
	{
		capTurtles *= 2;
		Turtle **tempTurtle = new Turtle*[capTurtles];
		
		for (int i = 0; i < capTurtles; ++i)
		{
			tempTurtle[i] = nullptr;
		}

		for (int i = 0; i < numTurtles; ++i)
		{
			tempTurtle[i] = turtles[i];
		}

		delete [] turtles;
		turtles = tempTurtle;
	
		turtles[index] = new Turtle;
		turtles[index]->setAge(age);
		++numTurtles;
	}		
	else
	{
		turtles[index] = new Turtle;
		turtles[index]->setAge(age);
		++numTurtles;
	}
}
