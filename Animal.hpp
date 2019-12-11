/****************************************88
 * Program Name: Zoo Tycoon
 * Author: Daniel Yopp
 * Date: 4/25/18	
 * Description: Animal.hpp contains the prototypes for Animal class
 * ****************************************/
 
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	private:
		int age;
		int cost;
		int numberOfBabies;
		double base;
		double payoff;
		
	public:
		void setAge(int);
		int getAge();
		void setCost(int);
		int getCost();
		void setNumberOfBabies(int);
		int getNumberOfBabies();
		void setBase(double);
		double getBase();
		void setPayoff(double);
		double getPayoff();


		
};






#endif 


