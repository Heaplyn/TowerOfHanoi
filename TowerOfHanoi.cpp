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
	while (!QuitFlag) {
		ClearTowers();
		SetupTowers();
		this_thread::sleep_for(chrono::seconds(1));
	}
	
}


void SetupTowers() {
	int towers = 0;
SetupTowers:
	
	cout << "How many towers would you like to have? ";
	cin >> towers;
	
	if (cin.fail()) {
		cout << "Try again\n ";
		towers = NULL;
		//both do sweep of buffer and reset failbit
		//\n is needed cause it clears everything up till the enter line
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	for (int i = 0; i < towers; i++) {
		tower NewTower;
		Towers.push_back(NewTower);
	}
}

void ClearTowers() {
	Towers.clear();
};

void PrintTowers() {
	for (int i = 0; i < Towers.size(); i++) {
		Towers.at(i).PrintTower(i);
	}
}