#include "Hiscores.h"
#include <iostream>

int main()
{
	Hiscores<const char*> hiscores;

	// Insert all players
	hiscores.insert("Luigi", 0);
	hiscores.insert("Mario", 0);
	hiscores.insert("Daisy", 0);
	hiscores.insert("Wario", 0);
	hiscores.insert("Koopa", 0);
	hiscores.insert("Peach", 0);
	hiscores.insert("Yoshi", 0);
	hiscores.insert("Toad",  0);

	std::cout << "Starting hi scores" << std::endl;
	hiscores.print();
	std::cout << std::endl;


	// Update scores (round 1)
	hiscores.update("Daisy", 2);
	hiscores.update("Wario", 5);
	hiscores.update("Koopa", 6);
	hiscores.update("Peach", 1);

	std::cout << "Hi scores after round 1" << std::endl;
	hiscores.print();
	std::cout << std::endl;


	// Update scores (round 2)
	hiscores.update("Yoshi", 9);
	hiscores.update("Toad",  4);
	hiscores.update("Luigi", 3);
	hiscores.update("Mario", 8);

	std::cout << "Hi scores after round 2" << std::endl;
	hiscores.print();
	std::cout << std::endl;


	// Update scores (round 3)
	hiscores.update("Wario", 6);
	hiscores.update("Toad",  6);
	hiscores.update("Mario", 9);
	hiscores.update("Yoshi", 10);

	std::cout << "Hi scores after round 3" << std::endl;
	hiscores.print();
	std::cout << std::endl;

	system("pause");

	return 0;
}

