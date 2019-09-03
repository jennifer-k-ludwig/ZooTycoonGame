/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Implementation file for Penguin class.
***************************************************************/
#include "Animal.hpp"
#include "Penguin.hpp"

Penguin::Penguin()
{
	cost = 1000;
	babies = 5;
	foodCost = baseFoodCost;
	payoff = 0.1 * cost;
}

