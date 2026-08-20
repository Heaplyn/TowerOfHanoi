#include "Hanoi.h"
#include <iostream>

using namespace Hanoi;

namespace Hanoi {
    int StartWeight = 0;
}

bool tower::operator==(const tower& other) const {
    return ID == other.ID;
}

tower::tower() {
    // Constructor logic
}

void tower::MoveDisk(disk Disk, tower& targetTower) {
    string DiskID = Disk.GetID();
    Disks -= DiskID;
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
