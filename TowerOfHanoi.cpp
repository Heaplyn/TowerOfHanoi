/*
Heaplyn, 8/19/26
Tower of Hanoi program that can have n disks and n pegs
*/

#include <iostream>
#include <vector>
#include <thread>
#include "Rings/Ring2/Hanoi.h"
#include "Rings/Ring0/StringUtil.h"

using namespace Hanoi;

bool QuitFlag = false;

void SetupTowers();
void PrintTowers();
void EnterMove();

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

void EnterMove() {
	int sourceTower = 0;
	int targetTower = 0;
	TryEnter:
		cout << "Enter the source tower number: ";
		cin >> sourceTower;
		cout << "Enter the target tower number: ";
		cin >> targetTower;
	if (sourceTower < 0 || sourceTower >= tower::Towers.size() ||
		targetTower < 0 || targetTower >= tower::Towers.size()) {
		cout << "Invalid tower numbers. Please try again." << endl;
		goto TryEnter;
		
	}
	tower& source = tower::Towers[sourceTower];
	tower& target = tower::Towers[targetTower];
	if (source.Disks.Size == 0) {
		cout << "Source tower is empty. Please try again." << endl;
		return;
	}
	disk topDisk = source.Disks[0];
	if (!target.VerifyDisk(topDisk)) {
		cout << "Cannot place disk on target tower. Please try again." << endl;
		return;
	}
	source.MoveDisk(topDisk, target);
	PrintTowers();
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
	tower::Towers.push_back(NewTower);
	//Towers - 1 considering we already added one tower with all disks
	for (int i = 0; i < towers - 1; i++) {
		tower NewTower;
		tower::Towers.push_back(NewTower);
	}
Round:
	PrintTowers();
	
}



void PrintTowers() {
	for (int i = 0; i < tower::Towers.size(); i++) {
		tower::Towers.at(i).PrintTower(i);
	}
}