#pragma once
#include <map>
#include <vector>
#include <string>
#include <variant>

using namespace std;

//Unfortunately cant use map for this
template<typename object>
using idVector = vector<object>;
template<typename object>
using idIterator = typename idVector<object>::const_iterator;
template<typename object>
using idPointer = typename idVector<object>::const_pointer;

template<typename object>
class Iterator {
private:
    //Const_iterator allows for easier debugging as const cant be changed.
    idPointer<object> ptr;

public:
    explicit Iterator(idPointer<object> p) : ptr(p) {}

    // Required for range-based for: dereference
    const object& operator*() { return *ptr; }

    // Required for range-based for: inequality comparison
    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }

    // Required for range-based for: pre-increment
    Iterator& operator++() {
        ++ptr;
        return *this;
    }
};

template<typename object>
class idManager {
private:
    idVector<object> Storage;

public:
    idManager() {}

    object operator[](const object ID) {
        //Basically is finding the ID in storage
        for (const object& s : Storage) {
            if (s == ID) return s;
        }
        return object();
    }

    void operator+=(const object ID) {
        for (const object& s : Storage) {
            if (s == ID) return;
        }
        Storage.push_back(ID);
    }

    void operator-=(const object ID) {
       for (int Index = 0; Index != Storage.size(); Index++) {
            if (Storage[Index] == ID) {
                Storage.erase(Storage.begin() + Index);
                return;
            }
        }
    }

    bool operator==(const idManager<object>& other) const {
        return Storage == other.Storage;
    }

    /*For the beginning bookmark of the storage thing
    Think of an iterator like a page in a book. 
    you have its address and you can move to n amount of pages or wtv
    */

    //Beginning iterator
    Iterator<object> begin() {
        return Iterator<object>(Storage.data());
    }

    //Ending iterator
    Iterator<object> end() {
        return Iterator<object>(Storage.data() + Storage.size());
    }
};
