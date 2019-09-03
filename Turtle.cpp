/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Implementation file for Turtle class.
***************************************************************/
#include "Animal.hpp"
#include "Turtle.hpp"

Turtle::Turtle()
{
	cost = 100;
	babies = 10;
	foodCost = 0.5 * baseFoodCost;
	payoff = 0.05 * cost;
}
