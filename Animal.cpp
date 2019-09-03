/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Implementation file for Animal class.
***************************************************************/
#include "Animal.hpp"

//Constructor
Animal::Animal()
{ age = 1; }

//Setters
void Animal::setAge(int age)
{ this->age = age; }

//Getters
int Animal::getAge()
{ return age; }

double Animal::getCost()
{ return cost; }

int Animal::getBabies()
{ return babies; }

double Animal::getFoodCost()
{ return foodCost; }

double Animal::getPayoff()
{ return payoff; }

//Methods
void Animal::getOlder()
{ age++; }


