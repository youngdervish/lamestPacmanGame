#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;

void clearScreen() { cout << "\033[H"; }

void createBox(int boxSize, int playerPositionX, int playerPositionY) {
	system("CLS");

	for (int i = 0; i < boxSize; i++)
	{
		for (int j = 0; j < boxSize; j++)
		{
			if (i == playerPositionX && j == playerPositionY) {
				cout << "\033[32m$ ";
			}
			else {
				cout << "\033[0m* ";
			}
		}
		cout << "\n";
	}
	cout << "\n\033[36mYou can click z to exit\n";
}

void main() {
	cout << "Welcome to the lamest Pacman game ever where all you do is move around.\nPlease enter the size of the box you'd like to thrash about:\n";
	int userDefinedBoxSize = 1;

	while (userDefinedBoxSize < 2) {
		cout << "Please keep in mind that the table size can't be smaller than 2\n";
		cin >> userDefinedBoxSize;
	}

	int ppX = 0, ppY = 0;
	createBox(userDefinedBoxSize, ppX, ppY);

	cout << "\nPlease use the arrow keys in the keyboard to move about:\n";
	int userMovement;
	while (true) {
		userMovement = _getch();
		if (userMovement == 72 || userMovement == 80 || userMovement == 75 || userMovement == 77 || userMovement == 122) {
			switch (userMovement) {
			case 72:
				cout << "UP";
				if (ppX > 0) ppX--;
				else { 
					cout << "\n\033[31mCan't move that way for now\n";
					sleep_for(milliseconds(500));	//system("PAUSE");
				}
				break;
			case 80: 
				cout << "DOWN";
				if (ppX < userDefinedBoxSize - 1) ppX++;
				else {
					cout << "\n\033[31mCan't move that way for now\n";
					sleep_for(milliseconds(500));	//system("PAUSE");
				}
				break;
			case 75:
				cout << "LEFT";
				if (ppY > 0) ppY--;
				else {
					cout << "\n\033[31mCan't move that way for now\n";
					sleep_for(milliseconds(500));	//system("PAUSE");
				}
				break;
			case 77:
				cout << "RIGHT";
				if (ppY < userDefinedBoxSize - 1) ppY++;
				else {
					cout << "\n\033[31mCan't move that way for now\n";
					sleep_for(milliseconds(500));	//system("PAUSE");
				}
				break;
			case 122:
				exit(1);
			default:
				break;
			}
			createBox(userDefinedBoxSize, ppX, ppY);
		}
	}
}




