/*
Heaplyn, 8/19/26
Decided a new naming convention camelCase for classes,
PascalCase for funcs and variables
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <random>

#include "Rings/Ring0/StringUtil.h"
#include "Rings/Ring1/IDManager.h"

using namespace std;

namespace Hanoi {
    extern int StartWeight;

    // Forward declaration so disk knows tower exists
    class tower;

    class disk {
    private:
        tower* TowerParent; // Pointer avoids circular reference & copy issues
        int Weight;
        string ID;
    public:
        string GetID();
        disk(tower* parent);
    };

    class tower {
    private:
        idManager Disks;
        void RemoveDisk(disk Disk);
        string ID;
    public:
        void MoveDisk(disk Disk, tower& targetTower);
        void PrintTower(int towerNum);
        bool operator==(const tower& other) const;
        tower();
    };
}
