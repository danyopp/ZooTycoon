/*************************************
 * Program Name: Zoo Tycoon 
 * Author: Daniel Yopp
 * Date: 4/25/17	
 * Description: Zoo.hpp contains prototypes for Zoo class
 * **********************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp" 

class Zoo
{
	private:
		int money;
		int day;
		int tigerCount;		//# of current Tigers
		Animal** tigerPTR;	//pointer to Tiger array
		int tigerArraySize;	// size of tiger array
		int penguinCount;
		Animal** penguinPTR;
		int penguinArraySize;
		int turtleCount;
		Animal** turtlePTR;
		int turtleArraySize;
	public:
		Zoo();
		~Zoo();
		//ensures arrays are big enough
		void checkTigerArraySize();
		void checkPenguinArraySize();
		void checkTurtleArraySize();

		void gameStart();
		void gameMenu();
		void animalPrint();
		void moneyPrint();
		void purchaseAnimals();
		void advanceDay();
		void randomEvent();	
	
		void setTigerArraySize(int);
		int getTigerArraySize();
		void setPenguinArraySize(int);
		int getPenguinArraySize();
		void setTurtleArraySize(int);
		int getTurtleArraySize(); 
		
		void setMoney(int);
		int getMoney();
		void setTigerCount(int);
		int getTigerCount();
		void setPenguinCount(int);
		int getPenguinCount();
		void setTurtleCount(int);
		int getTurtleCount();

		void createNewTiger(int);
		void createNewPenguin(int);
		void createNewTurtle(int); 

		void killTiger();
		void killPenguin();
		void killTurtle();



// zoo boom based on tigers
// have baby
// increase age

};
		

#endif 	
