/***************************
 * Program Name: Zoo Tycoon
 * Author: Daniel Yopp
 * Date: 4/25/18
 * Description: the mainZoo.cpp file links together all the functions of Zoo, Animal, Tiger, Penguin and Turtle classes to create Zoo Tycoon program.	
 * ***************************/
#include <cstdlib>
#include <ctime>
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"



int main()
{
	//Set seeds for random number picks
	unsigned seed;
	seed = time(0);
	srand(seed);

	Zoo game;
	const int startingMoney = 100000;
	game.setMoney(startingMoney);

	game.gameStart();
  
	game.gameMenu();


	return 0;
}
