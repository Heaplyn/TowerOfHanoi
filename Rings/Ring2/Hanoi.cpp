/*
Heaplyn, 8/20/26
Hanoi objects
*/
#include "Hanoi.h"

using namespace Hanoi;

namespace Hanoi {
    int StartWeight = 0;
	void ClearTowers() {
		cout << "Clearing towers..." << endl;
		StartWeight = 0;
		for (tower& t : tower::Towers) {
			t.ClearDisks();
		}
        tower::Towers.clear();
        tower::Towers.shrink_to_fit();
	}
}

vector<tower> tower::Towers = vector<tower>();

bool tower::operator==(const tower& other) const {
    return ID == other.ID;
}

bool disk::operator==(const disk& other) const {
    return ID == other.ID;
}

tower::tower(int Towers) {
	for (int i = Towers; i > 0; i--) {
		Disks += disk(this,i);
	}
    ID = GenerateRandomString();
}

bool tower::VerifyDisk(disk Disk) {
	if (Disks.Size == 0) {
		return true;
	}
	if (Disks[Disks.Size - 1].GetWeight() < Disk.GetWeight()) {
		return false;
	}
	return true;
}

void tower::MoveDisk(disk Disk, tower& targetTower) {
    Disks -= Disk;
    targetTower.Disks += Disk;
}

void tower::ClearDisks() {
	Disks.Clear();
}

void tower::PrintTower(int towerNum) {
    std::cout << "T" << towerNum << ": ";
	int Index = 0;
    for (disk Disk : Disks) {
        std::cout << Disk.GetName() << (Index < Disks.Size - 1 ? "==" : "");
		Index++;
    }
    std::cout << std::endl;
}

string disk::GetName() const {
    return (const string&)Name;
}

string disk::GetID() const {
    return (const string&)ID;
}
int disk::GetWeight() const {
	return Weight;
}

disk::disk(tower* parent, int NewWeight) {
    TowerParent = parent;
    switch (NewWeight) {
	case -1:
		Weight = StartWeight;
		break;
	default:
		Weight = NewWeight;
		break;
    }
    ID = GenerateRandomString();
    Name = DetermineDiskName(Weight);
}

disk::disk() : TowerParent(nullptr), Weight(-1), ID(""), Name("") {
	
}
