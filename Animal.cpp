/*****************************************
 * Program Name: Zoo Tycoon
 * Author: Daniel Yopp
 * Date: 4/25/18
 * Description: Animal.cpp contains the functions for Animal class that is used as a parent class for multiple types of animals
 * ***************************************/
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

/****************************************
 *	Get and Set functions
 * Descriptions: These get and set functions are used to alter the member variables of Animal class
 * *************************************/ 
void Animal::setAge(int ageinput)
{
	age = ageinput;
}

int Animal::getAge()
{
	return age;
}

void Animal::setCost(int costinput)
{
	cost = costinput;
}

int Animal::getCost()
{
	return cost;
}

void Animal::setNumberOfBabies(int numBabies)
{
	numberOfBabies = numBabies;
}

int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}

void Animal::setBase(double baseInput) 
{
	base = baseInput;
}

double Animal::getBase()
{
	return base;
}

void Animal::setPayoff(double payoffInput)
{
	payoff = payoffInput;
}

double Animal::getPayoff()
{
	return payoff;
}


