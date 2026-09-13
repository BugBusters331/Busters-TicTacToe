#include <iostream>
using namespace std;

void MainMenu() {

	int choice;

	cout << "---------------------------" << endl;
	cout << "|  Welcome to Tic-Tac-Toe |" << endl;
	cout << "|-------------------------|" << endl;
	cout << "| Please Select 1, 2 or 3 |" << endl;
	cout << "|-------------------------|" << endl;
	cout << "|         1. Play         |" << endl;
	cout << "|      2. User Manual     |" << endl;
	cout << "|         3. Exit         |" << endl;
	cout << "---------------------------" << endl;

	cin >> choice;

}
// Functions can be placed here, for example:
// void displayBoard() {}



int main() {

	MainMenu();
	// Additional game logic will go here


	return 0;
}