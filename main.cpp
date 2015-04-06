#include <iostream>
#include "World.h"
#include "Cell.h"


int main()
{
	int hight, width;
	std::cin >>hight;
	std::cin >> width;
	//создаем мир
	World MyWorld(hight, width);

	//как мы зададим живые клетки? мышью хотели. тогда уже нужно Qt юзать? 
	while (MyWorld.replay())
	{
		MyWorld.doStep();
	}
	return 0;

}
