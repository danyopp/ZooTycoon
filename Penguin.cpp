/**************************************
 * Program Name: Zoo Tycoon
 * Author: Daniel Yopp
 * Date: 4/25/18
 * Description: Penguin.cpp inherits all its members and functions from ANimal class but uses its own constructor to build each penguin object  
 * *********************************/

#include "Animal.hpp"
#include "Penguin.hpp"

Penguin::Penguin()
{
	setAge(0);
	setCost(1000);
	setNumberOfBabies(5);
	setBase(1);
	setPayoff(0.1);
} 
