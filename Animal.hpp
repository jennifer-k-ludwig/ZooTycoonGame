/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Header file for Animal class.
***************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		int age;
		double cost;
		int babies;
		double foodCost;
		double payoff;
		const double baseFoodCost = 10.0;

	public:
		//Constructor
		Animal();
	
		//Setters
		void setAge(int);

		//Getters
		int getAge();
		double getCost();
		int getBabies();
		double getFoodCost();
		double getPayoff();
		
		//Methods
		void getOlder();
};
#endif
