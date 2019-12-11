/***********************************************
 * Program Name: Zoo Tycoon
 * Author: Daniel Yopp
 * Date: 4/15/18
 * Description: Zoo class contains the functions that manipulate Animal class and its subclasses into the game zoo tycoon.
 * ********************************************/

#include <cstdlib>
#include <iostream>
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"	

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************
 * 	Zoo::Zoo
 * Description: Constructor arrays of Animal pointers to store the location of any animal objects in the game.
 * It also sets array counters for the game to use to resize the arrays as needed. 
 *******************************************/	
Zoo::Zoo()
{
	tigerPTR = new Animal*[10];
	penguinPTR = new Animal*[10];
	turtlePTR = new Animal*[10];

	tigerArraySize = 10;
	penguinArraySize = 10;
	turtleArraySize = 10;
	
	setTigerCount(0);
	setPenguinCount(0);
	setTurtleCount(0);

	day = 1;	
}	

/**********************************************
 *	Zoo::~Zoo
 * Description: deconstructor deletes all memory allocated to each object and 
 * then deletes the arrays that stored the object locations
 * *******************************************/

Zoo::~Zoo()
{
	int totalTigers = getTigerCount();
	for (int count = 0; count < totalTigers; count++)
	{
		delete tigerPTR[count];
	}

	int totalPenguins = getPenguinCount();
	for (int count = 0; count < totalPenguins; count++)
	{
		delete penguinPTR[count];
	}

	int totalTurtles = getTurtleCount();
	for (int count = 0; count < totalTurtles; count++)
	{
		delete turtlePTR[count];
	} 
	
	delete [] tigerPTR;
	delete [] penguinPTR;
	delete [] turtlePTR;
}

/********************************************
 *	Zoo::gameStart()
 * Description: function prompts user the necessary questions to set up a new game of Zoo tycoon.
 * It allows a user to select to buy either one or two animals and then purchases the animals and debits the money variable. 
 * *****************************************/

void Zoo::gameStart()
{
	int tigerCost = 10000;
	int penguinCost = 1000;
	int turtleCost = 100;

	cout <<endl << "To start a game of Zoo Tycoon you must select animals to populate your zoo." << endl;
	cout << "You can choose to purchase either 1 or 2 of each animal to start." <<endl;
	cout << "Your starting money is: $" << money << endl; 
	cout << "The following animals are avalible:" << endl;
	cout << "   Tigers:   $" << tigerCost << endl;
	cout << "   Penguins: $" << penguinCost << endl;
	cout << "   Turtles:  $" << turtleCost << endl;

	bool inputVerification = false;
	int tigerBuy;
	while(inputVerification == false)
	{
	    cout << "Please enter the number of Tigers you would like to purchase." <<endl;
	    string tigerSTR;
	    getline(cin, tigerSTR);
	    if(tigerSTR == "1" || tigerSTR == "2")
		{
		 inputVerification = true;
		 tigerBuy = stoi(tigerSTR);
		}
	    else
		{
		 cout << "INVALID USER INPUT! Please enter either 1 or 2" << endl;
		}
	 }
	if(tigerBuy == 1)
	 {
	    createNewTiger(1);
	    int cash = getMoney();
	    setMoney(cash-tigerCost);
	    cout << "You have purchased 1 tiger for $" << tigerCost << endl;
	    cout << "You have $" << getMoney() << " remaining." << endl;
	 }
	else    	
	 {
	    createNewTiger(1);
	    createNewTiger(1); 
	    int cash = getMoney();
	    setMoney(cash-tigerCost-tigerCost);
	    cout << "You have purchased 2 tigers for $" << (tigerCost*2) << endl;
	    cout << "You have $" << getMoney() << " remaining." << endl;
	 }	
//penguins
	int penguinBuy;
	inputVerification =false;
	while(inputVerification == false)
	{
	    cout << "Please enter the number of Penguins you would like to purchase." <<endl;
	    string penguinSTR;
	    getline(cin, penguinSTR);
	    if(penguinSTR == "1" || penguinSTR == "2")
		{
		 inputVerification = true;
		 penguinBuy = stoi(penguinSTR);
		}
	    else
		{
		 cout << "INVALID USER INPUT! Please enter either 1 or 2" << endl;
		}
	 }
	if(penguinBuy == 1)
	 {
	    createNewPenguin(1);
	    int cash = getMoney();
	    setMoney(cash-penguinCost);
	    cout << "You have purchased 1 penguin for $" << penguinCost << endl;
	    cout << "You have $" << getMoney() << " remaining." << endl;
	 }
	else    	
	 {
	    createNewPenguin(1);
	    createNewPenguin(1); 
	    int cash = getMoney();
	    setMoney(cash-penguinCost-penguinCost);
	    cout << "You have purchased 2 penguins for $" << (penguinCost*2) << endl;
	    cout << "You have $" << getMoney() << " remaining." << endl;
	 }	
//turtles

	int turtleBuy;
	inputVerification =false;
	while(inputVerification == false)
	{
	    cout << "Please enter the number of Turtles you would like to purchase." <<endl;
	    string turtleSTR;
	    getline(cin, turtleSTR);
	    if(turtleSTR == "1" || turtleSTR == "2")
		{
		 inputVerification = true;
		 turtleBuy = stoi(turtleSTR);
		}
	    else
		{
		 cout << "INVALID USER INPUT! Please enter either 1 or 2" << endl;
		}
	 }
	if(turtleBuy == 1)
	 {
	    createNewTurtle(1);
	    int cash = getMoney();
	    setMoney(cash-turtleCost);
	    cout << "You have purchased 1 turtle for $" << turtleCost << endl;
	    cout << "You have $" << getMoney() << " remaining." << endl;
	 }
	else    	
	 {
	    createNewTurtle(1);
	    createNewTurtle(1); 
	    int cash = getMoney();
	    setMoney(cash-turtleCost-turtleCost);
	    cout << "You have purchased 2 Turtles for $" << (turtleCost*2) << endl;
	    cout << "You have $" << getMoney() << " remaining." << endl;
	 }	

}
/****************************************************
 *	Zoo::gameMenu()
 * Description: This main menu function is persented to the user each day and allows the user 
 * to select how they would like to proceed. The function input is verified and then this functon
 * calls the appropriate function to complete the user requested task.
 * *************************************************/
void Zoo::gameMenu()
{
	int menuOption;
	bool inputVerification =false;
	while(inputVerification == false)
	{
	cout << " --------------------------" << endl;
	cout << " Today is Day " << day << endl;            
	cout << " These are your options: "<< endl;
	cout << " 1. Advance to next day " << endl;
	cout << " 2. View Animals " << endl;
	cout << " 3. View Money	" << endl;
	cout << " 4. Purchase Animals " << endl;
	cout << " 5. Quit Game " << endl;
	cout << "--------------------------" << endl;
	cout <<" Please select an option:";
	    
	    string menuOptionSTR;
	    getline(cin, menuOptionSTR);
	    if(menuOptionSTR == "1" || menuOptionSTR == "2" || menuOptionSTR == "3" || menuOptionSTR == "4" || menuOptionSTR == "5")
		{
		 inputVerification = true;
		 menuOption = stoi(menuOptionSTR);
		}
	    else
		{
		 cout << "INVALID USER INPUT! Please enter either 1, 2, 3, 4, or 5" << endl;
		}
	}
	if(menuOption == 1)
	{
		advanceDay();
	} 
	
	if(menuOption == 2)
	{
		animalPrint();
	}

	if(menuOption == 3)
	{
		moneyPrint();
	}
	if(menuOption ==4)
	{
		purchaseAnimals();
	}

}

/**************************************************
 *	Zoo::checkTigerArraySize
 * Description: This function checks the tiger pointer array and creates a larger array if it is needed to store additional tiger objects.	
 * ***********************************************/
void Zoo::checkTigerArraySize()
{	
	int ArraySize = getTigerArraySize();
	if (getTigerCount() >= (ArraySize - 1))
	   {
		Animal** tempholder = tigerPTR;
	
		setTigerArraySize(ArraySize+10);
		ArraySize = getTigerArraySize();

		tigerPTR = new Animal*[ArraySize];
		
		for (int count = 0; count < tigerCount; count++)
			{
			 tigerPTR[count] = tempholder[count];	 	 
			}
		delete [] tempholder;
		tempholder = 0;
	   }
}

/*********************************************
 *	Zoo::checkPenguinArraySize
 *Description: This function checks the penguin pointer array and creates a larger array if it is needed to store additional penguin objects.
 * ******************************************/
void Zoo::checkPenguinArraySize() 
{
	int ArraySize = getPenguinArraySize();
	if (getPenguinCount() >= (ArraySize - 1))
	   {
		Animal** tempholder = penguinPTR;
		setPenguinArraySize(ArraySize+10);
		ArraySize = getPenguinArraySize();
		
		penguinPTR = new Animal*[ArraySize];

		for(int count = 0; count < penguinCount; count++)
		   {
			penguinPTR[count] = tempholder[count];
		   }
		
		delete [] tempholder;
		tempholder = 0;
	   }
}

/********************************************
 *	Zoo::checkTurtleArraySize
 *Description: This function checks the penguin pointer array and creates a larger array if it is needed to store additional penguin objects.
 * *****************************************/
void Zoo::checkTurtleArraySize()
{
	int ArraySize = getTurtleArraySize();
	if (getTurtleCount() >= (ArraySize - 1))
	   {
		Animal** tempholder = turtlePTR;
		setTurtleArraySize(ArraySize + 10);
		ArraySize = getTurtleArraySize();
	
		turtlePTR = new Animal*[ArraySize];

		for(int count=0; count < turtleCount; count++)
		   {
			turtlePTR[count] = tempholder[count];
		   }

		delete [] tempholder;
		tempholder = 0;
	   }
}   

/*******************************************
 *	Zoo::animalPrint
 * Description: This function prints the number of the each Animal present in zoo and then lists the age for each animal 
 * *****************************************/
void Zoo::animalPrint()
{
	
	Animal* temp;

	cout << endl << "Total number of Tigers:" << getTigerCount() << endl;
	cout << "Tiger array size is " << getTigerArraySize() << endl;
	for(int count = 0; count < getTigerCount(); count++) 	
	{temp = tigerPTR[count];
	 cout << "Tiger " << (count +1) <<" is " << temp->getAge() << " days old." << endl;
	}

	cout << endl << "Total number of Penguins:" << getPenguinCount() << endl;
	cout << "Penguin array size is " << getPenguinArraySize() << endl;
	for(int count = 0; count < getPenguinCount(); count++) 	
	{temp = penguinPTR[count];
	 cout << "Penguin " << (count +1) <<" is " << temp->getAge() << " days old." << endl;
	}

	cout << endl << "Total number of Turtles:" << getTurtleCount() << endl;
	cout << "Turtle array size is " << getTurtleArraySize() << endl;
	for(int count = 0; count < getTurtleCount(); count++) 	
	{temp = turtlePTR[count];
	 cout << "Turtle " << (count +1) <<" is " << temp->getAge() << " days old." << endl;
	}
	gameMenu();
}
/*******************************************
 *	Zoo::moneyPrint
 *Description: functions prints current amount of money on hand
 * ****************************************/


void Zoo::moneyPrint()
{
	cout << "Current money is: $" << getMoney() << endl;
	gameMenu();
}

/******************************************
 *	Zoo::purchaseAnimals
 *Description: the purchase animals function allows user to select an animal to buy. The cost of the animal is deducted from money and the animal starts as 3 days old
 * ***************************************/

void Zoo::purchaseAnimals()
{
	int menuOption;
	bool inputVerification =false;
	while(inputVerification == false)
	{
		cout << "----------------" << endl;
		cout << "1. Tigers:  $10,000" << endl;
		cout << "2. Penguins: $1,000" << endl;
		cout << "3. Turtles:    $100" << endl;		
		cout << "Current money: $" << getMoney() << endl; 
		cout << "-------------------" << endl;
		cout << "Please select an animal to purchase." << endl;

	    string menuOptionSTR;
	    getline(cin, menuOptionSTR);
	    if(menuOptionSTR == "1" || menuOptionSTR == "2" || menuOptionSTR == "3")
		{
		 inputVerification = true;
		 menuOption = stoi(menuOptionSTR);
		}
	    else
		{
		 cout << "INVALID USER INPUT! Please enter either 1, 2, or 3" << endl;
		}
	}

	if(menuOption == 1)
	{
		if(getMoney() > 9999)
		{ 
		   createNewTiger(3);
		   int currentMoney = getMoney();
		   setMoney(currentMoney-10000);	
		}
		else
		{
		   cout << "You do not have enough money to purchase a Tiger!" << endl;
		}
	}

	if(menuOption == 2)
	{
		if(getMoney() > 999)
		{ 
		   createNewPenguin(3);
		   int currentMoney = getMoney();
		   setMoney(currentMoney-1000);	
		}
		else
		{
		   cout << "You do not have enough money to purchase a Penguin!" << endl;
		}
	}

	if(menuOption == 3)
	{
		if(getMoney() > 99)
		{ 
		   createNewTurtle(3);
		   int currentMoney = getMoney();
		   setMoney(currentMoney-100);	
		}
		else
		{
		   cout << "You do not have enough money to purchase a Turtle!" << endl;
		}
	}
	gameMenu();
}

/***********************************************
 *	Zoo::advanceDay
 *Description: The advance day function advances the age of each animal 1 day, charges the user for the feed cost, and determines the animal bonuses for each day. If there is not enough money to pay for the feed, the function returns and the game ends. Otherwise the function ends by calling the random event function  
 * *******************************************/
void Zoo::advanceDay()
{
	day++;
	Animal* tempPTR;
	int oldAge;

	//increase age of animals
	for(int count = 0; count < getTigerCount(); count++) 	
	{
	 tempPTR = tigerPTR[count];
	 oldAge = tempPTR->getAge(); 
	 tempPTR->setAge(oldAge + 1);
	}

	for(int count = 0; count < getPenguinCount(); count++) 	
	{
	 tempPTR = penguinPTR[count];
	 oldAge = tempPTR->getAge(); 
	 tempPTR->setAge(oldAge + 1);
	}

	for(int count = 0; count < getTurtleCount(); count++) 	
	{
	 tempPTR = turtlePTR[count];
	 oldAge = tempPTR->getAge(); 
	 tempPTR->setAge(oldAge + 1);
	}

	//calculate feed cost
	const double foodCost = 10;
	double tempBase;
	double tigerFoodCost=0;
	double penguinFoodCost=0;
	double turtleFoodCost=0;

	for(int count = 0; count < getTigerCount(); count++) 	
	{
	 tempPTR = tigerPTR[count];
	 tempBase = tempPTR->getBase(); 
	 tigerFoodCost += (tempBase*foodCost);
	}

	for(int count = 0; count < getPenguinCount(); count++) 	
	{
	 tempPTR = penguinPTR[count];
	 tempBase = tempPTR->getBase(); 
	 penguinFoodCost += (tempBase*foodCost);
	}

	for(int count = 0; count < getTurtleCount(); count++) 	
	{
	 tempPTR = turtlePTR[count];
	 tempBase = tempPTR->getBase(); 
	 turtleFoodCost += (tempBase*foodCost);
	}

	cout << "Food cost for Tigers is: $" << tigerFoodCost << endl;
	cout << "Food cost for Penguins is: $" << penguinFoodCost << endl;
	cout << "Food cost for Turtles is: $" << turtleFoodCost << endl;
	int totalCost = (tigerFoodCost+ penguinFoodCost + turtleFoodCost);
	cout << "Total food cost: $" << totalCost << endl;
	cout << "Current money: $" << money << endl;	

	if(totalCost > money)
	{
	   cout << "You have run out of money and cannot afford the food costs for your animals" << endl;
	   cout << "GAME OVER!" << endl;
	}

	else
	{   money -= totalCost;
	    cout << "Money remaining after food costs: $" << money << endl;  		

		int TigerPayout=0, PenguinPayout=0, TurtlePayout=0;
	//determine bonus for animals 
		for(int count = 0; count < getTigerCount(); count++) 	
		{
		 tempPTR = tigerPTR[count];
		 double payoff = tempPTR->getPayoff(); 
		 double cost= tempPTR->getCost(); 
		 TigerPayout += (payoff*cost);
		}

		for(int count = 0; count < getPenguinCount(); count++) 	
		{
		 tempPTR = penguinPTR[count];
		 double payoff = tempPTR->getPayoff(); 
		 double cost= tempPTR->getCost(); 
		 PenguinPayout += (payoff*cost);
		}

		for(int count = 0; count < getTurtleCount(); count++) 	
		{
		 tempPTR = turtlePTR[count];
		 double payoff = tempPTR->getPayoff(); 
		 double cost= tempPTR->getCost(); 
		 TurtlePayout += (payoff*cost);
		}
		cout << "The payout for your animals is as follows" << endl;
		cout << " Tigers: $" << TigerPayout << endl;
		cout << " Penguins: $" << PenguinPayout << endl;
		cout << " Turtles: $" << TurtlePayout << endl;
		int TotalPayout = TigerPayout + PenguinPayout + TurtlePayout;
		cout << " Total Payout: $" << TotalPayout << endl;
		money += TotalPayout;

	//call random event
	   randomEvent();
	   gameMenu();
	}
}

/*************************************************
 *	Zoo::randomEvent
 *Description: This function selexts one of four events to happen at the end of each day. 
 The first is a random animal dies. 
 the second is a bonus from an attendance boom, 
 the third is the brith of a new animal. Before a birth, 
 		the randomly selected parent animal is checked to ensure they are 3 days old. 
 		If they are not old enough then no event happens. 
 The fouth option is also that No Event Happens.
 * ***********************************************/
void Zoo::randomEvent()

{
	int event = ((rand()%4)+1);
	
	//animal dies
	if(event == 1)
	{
 	 int animaltype = ((rand()%3)+1);
	 if(animaltype == 1)
	    {	
		killTiger();
	    }
	 if(animaltype == 2)
	    {	
		killPenguin();
	    }
	 if(animaltype == 3)
	    {	
		killTurtle();
	    }
	}

	//boom in attendence
	if(event == 2)
	{
	 int bonus = ((rand()%250)+251);
	 int totalBonus = getTigerCount() * bonus;
	 cout << "You recieved a bonus of $" << bonus << " for each tiger you own." << endl;
	 cout << "Your total bonus is $" << totalBonus <<endl;
	 money += totalBonus;
	}

	//animal born

	if(event == 3)
	{	
  	 int animaltype = ((rand()%3)+1);

	 if(animaltype == 1)
	    {
			int count = getTigerCount();
			if(count > 0)
			{	
				int testTiger = (rand() % count);
				int tigerAge = tigerPTR[testTiger]->getAge();
				if(tigerAge > 2) 
				{
				createNewTiger(0);
				}
				else
				{cout << "Tiger not old enough to have babies. No event" << endl;}
    		}
    		else
    		{cout << "No tigers to have birth" << endl;}	
	    }	
	 if(animaltype == 2)
	    {	
			int count = getPenguinCount();
			if(count > 0)
			{	
				int testPenguin = (rand() % count);
				int PenguinAge = penguinPTR[testPenguin]->getAge();
				if(PenguinAge > 2) 
				{
					createNewPenguin(0);
					createNewPenguin(0);
					createNewPenguin(0);
					createNewPenguin(0);
					createNewPenguin(0);
				}
				else
				{cout << "Penguin not old enough to have babies. No event" << endl;}
	    	}
	    	else
	    	{cout << "No penguins to have birth" << endl;}		
	    }		
	 if(animaltype == 3)
	    {	
			int count = getTurtleCount();
			if(count > 0)
			{	
				int testTurtle = (rand() % count);
				int TurtleAge = turtlePTR[testTurtle]->getAge();
				if(TurtleAge > 2) 
				{
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
					createNewTurtle(0);
				}
				else
				{cout << "Turtle not old enough to have babies. No event" << endl;}
			}
			else
			{cout << "No turtles to have birth" << endl;}	
	    }
	}

	//nothing happens
	if(event == 4)
	{
	 cout << "Nothing happened this turn" << endl;
	}

}

/****************************************
 *	Zoo::createNewTiger
 *Description: Function dynamically creates a new Tiger object and adds its location to the tiger pointer array
 * *************************************/
void Zoo::createNewTiger(int age)
{	
	checkTigerArraySize();
	
	int TotalTigers = getTigerCount();
	
	tigerPTR[TotalTigers] = new Tiger;

	tigerPTR[TotalTigers]->setAge(age);

	setTigerCount(TotalTigers+1);

	cout << "You have a new Tiger!" << endl;	   
}		

/***************************************
 *	Zoo::createNewPenguin
 *Description: Function dynamically creates a new Penguin object and adds its location to the Penguin pointer array
 * ************************************/
void Zoo::createNewPenguin(int age)
{
	checkPenguinArraySize();

	int TotalPenguins = getPenguinCount();

	penguinPTR[TotalPenguins] = new Penguin;

	penguinPTR[TotalPenguins]->setAge(age);

	setPenguinCount(TotalPenguins+1);

	cout << "You have a new Penguin!" <<endl;
}

/**************************************
 *	Zoo::createNewTurtle
 * Description: Function dynamically creates a new Turtle object and adds its location to the Turtle pointer array
 * ***********************************/
void Zoo::createNewTurtle(int age)
{
	checkTurtleArraySize();
	
	int TotalTurtles = getTurtleCount();

	turtlePTR[TotalTurtles] = new Turtle;

	turtlePTR[TotalTurtles]->setAge(age);    

	setTurtleCount(TotalTurtles+1);
	
	cout << "You have a new Turtle!" << endl;
}

/***********************************
 *	Zoo::killTiger
 *Description: This function randomly selects a Tiger and deletes it as if it had died. It then slides the rest of the array down to fill the vacancy the deleted object left.
 * ********************************/
void Zoo::killTiger()   //BE SURE TO TEST FOR TIGER BEFORE CALLING
{
	
	int tigerTotal = getTigerCount();	//5 tigers

	if(tigerTotal > 0)
	{	
		int deadTiger = (rand() % (tigerTotal)); //0-4

		delete tigerPTR[deadTiger];	//3

		for (int count = deadTiger; count < (tigerTotal-1); count++)
		   {
			tigerPTR[count] = tigerPTR[count+1];	//4->3
		   }
		setTigerCount(tigerTotal-1);
		cout << "A Tiger has died!" <<endl;
	}
	else
	{cout << "No tiger to die." << endl;}
}	
/********************************************
 * 	Zoo::killPenguin 
 *Description: This function randomly selects a Penguin and deletes it as if it had died. It then slides the rest of the array down to fill the vacancy the deleted object left.
 *******************************************/
void Zoo::killPenguin()
{
	int penguinTotal = getPenguinCount();

	if(penguinTotal > 0)
	{	
		int deadPenguin = (rand() % (penguinTotal));

		delete penguinPTR[deadPenguin];

		for(int count = deadPenguin; count < (penguinTotal-1); count++)
		  {
			penguinPTR[count] = penguinPTR[count+1];
		  }
		setPenguinCount(penguinTotal -1);
		cout << "A Penguin has died!" << endl;
	}
	else
	{	cout << "No penguin to die" << endl;	}	
}

/********************************************
 * 	Zoo::killTurtle 
 *Description: This function randomly selects a Turtle and deletes it as if it had died. It then slides the rest of the array down to fill the vacancy the deleted object left.
 *******************************************/
void Zoo::killTurtle()
{
	int turtleTotal = getTurtleCount();

	if(turtleTotal > 0)
	{	
		int deadTurtle = (rand() % (turtleTotal));

		delete turtlePTR[deadTurtle];

		for(int count = deadTurtle; count < (turtleTotal-1); count++)
		   {
			turtlePTR[count] = turtlePTR[count+1];
		   }
		setTurtleCount(turtleTotal -1);
		cout << "A Turtle has died!" << endl;
	}
	else
	{	cout << "No turtle to die" << endl;	}	
}	

/***************************************
 *	Get and Set Functions
 *Description: The following functions are either used to set the member variables or return the member variables for the Zoo class
 * *************************************/

void Zoo::setMoney(int moneyinput)
{
	money = moneyinput;
}

int Zoo::getMoney()
{
	return money;
}

void Zoo::setTigerCount(int countInput)
{
	tigerCount = countInput;
}

int Zoo::getTigerCount()
{
	return tigerCount;
}

void Zoo::setPenguinCount(int countInput)
{
	penguinCount = countInput;
}

int Zoo::getPenguinCount()
{
	return penguinCount;
}

void Zoo::setTurtleCount(int countInput)
{
	turtleCount = countInput;
}

int Zoo::getTurtleCount()
{
	return turtleCount;
}

void Zoo::setTigerArraySize(int input)
{
	tigerArraySize = input;
}

int Zoo::getTigerArraySize()
{
	return tigerArraySize;
}

void Zoo::setPenguinArraySize(int input)
{
	penguinArraySize = input;
}
	
int Zoo::getPenguinArraySize()
{
	return penguinArraySize;
}

void Zoo::setTurtleArraySize(int input)
{
	turtleArraySize = input;
}

int Zoo::getTurtleArraySize()
{
	return turtleArraySize;
}  	
