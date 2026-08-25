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
    // Forward declaration so disk knows tower exists
    class tower;

    extern int StartWeight;
    extern void ClearTowers();

    

    class disk {
    private:
        tower* TowerParent; // Pointer avoids circular reference & copy issues
        int Weight;
        string ID;
        string Name;

    public:
        string GetID() const;
        string GetName() const;
		int GetWeight() const;
        disk(tower* parent,int NewWeight = -1);
        disk();
        bool operator==(const disk& other) const;
    };

    class tower {
    private:
        void RemoveDisk(disk Disk);
        string ID;

    public:
        static vector<tower> Towers;
        idManager<disk> Disks;
        bool VerifyDisk(disk Disk);
        void MoveDisk(disk Disk, tower& targetTower);
        void PrintTower(int towerNum);
        bool operator==(const tower& other) const;
        tower(int Towers = 0);
        void ClearDisks();
    };
}
