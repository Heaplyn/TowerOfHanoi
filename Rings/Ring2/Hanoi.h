/*
Heaplyn, 8/19/26
Decided a new naming convention camelCase for classes,
PascalCase for funcs and variables
*/
#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "Rings/Ring0/StringUtil.h"
#include "Rings/Ring1/IDManager.h"

namespace Hanoi {
    extern int StartWeight;

    // Forward declaration so disk knows tower exists
    class tower;

    class disk {
    private:
        tower* TowerParent; // Pointer avoids circular reference & copy issues
        int Weight;
        string ID;
        string Name;

    public:
        string GetID() const;
        string GetName() const;
        disk(tower* parent);
        bool operator==(const disk& other) const;
    };

    class tower {
    private:
        idManager<disk> Disks;
        void RemoveDisk(disk Disk);
        string ID;

    public:
        bool VerifyDisk(disk Disk);
        void MoveDisk(disk Disk, tower& targetTower);
        void PrintTower(int towerNum);
        bool operator==(const tower& other) const;
        tower();
    };
}
