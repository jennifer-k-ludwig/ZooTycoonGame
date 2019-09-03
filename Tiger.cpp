/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/20/2019
 * Description: Implementation file for Tiger class.
***************************************************************/
#include "Animal.hpp"
#include "Tiger.hpp"

Tiger::Tiger() : Animal()
{
	cost = 10000;
	babies = 1;
	foodCost = 5 * baseFoodCost;
	payoff = 0.2 * cost;
}
