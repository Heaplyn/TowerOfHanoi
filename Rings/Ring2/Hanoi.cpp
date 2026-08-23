/*
Heaplyn, 8/20/26
Hanoi objects
*/
#include "Hanoi.h"

using namespace Hanoi;

namespace Hanoi {
    int StartWeight = 0;
}

bool tower::operator==(const tower& other) const {
    return ID == other.ID;
}

bool disk::operator==(const disk& other) const {
    return ID == other.ID;
}

tower::tower(int Towers) {
	for (int i = 0; i < Towers; i++) {
		Disks += disk(this);
	}
    ID = GenerateRandomString();
}

void tower::MoveDisk(disk Disk, tower& targetTower) {
    Disks -= Disk;
    targetTower.Disks += Disk;
}

void tower::PrintTower(int towerNum) {
    std::cout << "T" << towerNum << ": ";
    for (disk Disk : Disks) {
        std::cout << Disk.GetName() << " ";
    }
    std::cout << std::endl;
}

string disk::GetName() const {
    return (const string&)Name;
}

string disk::GetID() const {
    return (const string&)ID;
}

disk::disk(tower* parent) {
    TowerParent = parent;
    StartWeight++;
    Weight = StartWeight;
    ID = GenerateRandomString();
    Name = DetermineDiskName(Weight);
}
