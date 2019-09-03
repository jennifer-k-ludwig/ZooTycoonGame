/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Header file for Zoo class.
***************************************************************/
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Animal.hpp"

#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo
{
	private:
		//Variables
		double money;
		int numTigers, 
			numPenguins, 
			numTurtles, 
			capTigers, 
			capPenguins, 
			capTurtles;
		Tiger **tigers;
		Penguin **penguins;
		Turtle **turtles;

		//Methods
		void randomEvent();
		void animalDies();
		void tigerBonus();
		void babyBorn();	
		void askToBuyAnimal();
		void buyAnimal();
		void nothingHappens();
		int getRandomAnimal();
		void addTiger(int, int);
		void addPenguin(int, int);
		void addTurtle(int, int);

	public:
		//Constructors
		Zoo();
		Zoo(int, int, int);
		~Zoo();
		//Getters
		double getMoney();
		//Methods
		void day();
};
#endif
