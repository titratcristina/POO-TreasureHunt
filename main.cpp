#include <iostream>

using namespace std;

int main() {
	cout << "Welcome, stranger!\n";
	cout << "This is the Magic Forest.\n";
	cout << "You need to define the territory down below.\n";

	int x, y;

	do {
		cout << "Remember! The map can not be smallar than 15x15.\n";
		cout << "Choose carefully your numbers: \n";
		cin >> x >> y;
	} while (x < 15 || y < 15);
}
