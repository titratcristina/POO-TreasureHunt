#include <iostream>
#include "Game.h"
#include "Seekers.h"

using namespace std;

int main() {
	cout << "Welcome, stranger!\n";
	cout << "This is the Magic Forest.\n";
	cout << "You need to define the territory down below.\n";

	int size;

	do {
		cout << "Remember! The map can not be smallar than 15x15.\n";
		cout << "Choose your number carefully: \n" << "->";
		cin >> size;
	} while (size < 15);

	cout << "In this game four magical seekers will be searching for a lost diamond in forest.\n";
	cout << "Crazy Bee - first player\n"
		 << "Sleepy Bear - second player\n"
		 << "Drunk Raccoon - third player\n"
		 << "Last, but not least: Sweet Deer - fourth player\n";

	cout << "Be patient! You need to wait a little bit before the map loads.\n";

	Game forest(size);
	forest.playGame();
	return 0;
}
