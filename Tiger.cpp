/***************************************
 * Program Name: Zoo Tycoon
 * Author: Daniel Yopp
 * Date: 4/25/18
 * Description: Tiger.cpp is a derived class from Animal class
 * ************************************/

#include "Animal.hpp"
#include "Tiger.hpp"

Tiger::Tiger()
{
	Animal::setAge(0);
	setCost(10000);
	setNumberOfBabies(1);
	setBase(5);
	setPayoff(0.2);
}
	
