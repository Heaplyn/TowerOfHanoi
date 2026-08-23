#include "Hanoi.h"



using namespace Hanoi;

namespace Hanoi {
    int StartWeight = 0;
}

bool tower::operator==(const tower& other) const {
    return ID == other.ID;
}

tower::tower() {
    ID = GenerateRandomString();
}



void tower::MoveDisk(disk Disk, tower& targetTower) {
    string DiskID = Disk.GetID();
    Disks -= DiskID;
    targetTower.Disks += DiskID;
}

void tower::PrintTower(int towerNum) {
	std::cout << "Tower " << towerNum << " contains disks: ";
    for (disk Disk : Disks) {
        std::cout << Disk.GetID() << " ";
    }
	std::cout << std::endl;
}

string disk::GetID() {
    return ID;
}

disk::disk(tower* parent) {
    TowerParent = parent;
    StartWeight++;
    Weight = StartWeight;
    std::cout << "Disk created with weight: " << StartWeight << std::endl;
    std::cout << "Disk real weight: " << Weight << std::endl;
    ID = GenerateRandomString();
}


