/*************************************
 * Program Name: Zoo Tycoon
 * Author: Daniel Yopp
 * Date: 4/25/18
 * Description: Turtle.cpp contains turtle class which is just a derived class from Animal class
 * **********************************/

#include "Animal.hpp"
#include "Turtle.hpp"

Turtle::Turtle()
{
	setAge(0);
	setCost(100);
	setNumberOfBabies(10);
	setBase(0.5);
	setPayoff(0.05);
}
