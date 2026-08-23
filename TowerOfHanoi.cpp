/*
Heaplyn, 8/19/26
Tower of Hanoi program that can have n disks and n pegs
*/

#include <iostream>
#include <vector>
#include <thread>
#include "Rings/Ring2/Hanoi.h"
#include "Rings/Ring0/StringUtil.h"

using namespace std;
using namespace Hanoi;

vector<tower> Towers;
bool QuitFlag = false;

void ClearTowers();
void SetupTowers();
void PrintTowers();

int main()
{
	cout << GenerateRandomString(50) << endl;
	cout << "Welcome to the Tower of Hanoi program!" << endl;
	//while (!QuitFlag) {
	FlagLoop:
		ClearTowers();
		SetupTowers();
		this_thread::sleep_for(chrono::milliseconds(400));
	//}
	if (!QuitFlag) goto FlagLoop;
	return 0;
}

void SetupTowers() {
	int towers = 0;
	int Disks = 0;
SetupDisks:
	cout << "How many disks would you like to have? ";
	cin >> Disks;
	if (cin.fail()) {
		cout << "Try again\n ";
		Disks = 0;
		//both do sweep of buffer and reset failbit
		//if you dont reset failbit, itll keep failing recursively
		//\n is needed cause it clears everything up till the enter line
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//did this cause why not. hope youre happy professor :)
		//besides i can see the elegance in this
		goto SetupDisks;
		return;
	}
	if (Disks == -1) {
		QuitFlag = true;
		return;
	}
	if (Disks < 1) {
		cout << "You must have at least 1 disk. Setting to 1." << endl;
		Disks = 1;
	}

SetupTowers:
	
	cout << "How many towers would you like to have? ";
	cin >> towers;
	
	if (cin.fail()) {
		cout << "Try again\n ";
		towers = 0;
		//both do sweep of buffer and reset failbit
		//if you dont reset failbit, itll keep failing recursively
		//\n is needed cause it clears everything up till the enter line
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//did this cause why not. hope youre happy professor :)
		//besides i can see the elegance in this
		goto SetupTowers;
		return;
	}
	if (towers == -1) {
		QuitFlag = true;
		return;
	}
	if (towers < 3) {
		cout << "You must have at least 3 towers. Setting to 3." << endl;
		towers = 3;
	}
	tower NewTower(Disks);
	Towers.push_back(NewTower);
	for (int i = 0; i < towers - 1; i++) {
		tower NewTower;
		Towers.push_back(NewTower);
	}
	PrintTowers();
}

void ClearTowers() {
	Towers.clear();
}

void PrintTowers() {
	for (int i = 0; i < Towers.size(); i++) {
		Towers.at(i).PrintTower(i);
	}
}