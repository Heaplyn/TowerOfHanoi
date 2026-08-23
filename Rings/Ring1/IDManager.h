#pragma once
#include <map>
#include <vector>
#include <string>
#include <variant>

using namespace std;

typedef map<string, bool> idMap;
typedef vector<string> idVector;
typedef variant<idMap, idVector> idStorage;

// map for faster performance, vector for less memory usage
enum idType {
    Map,
    Vector
};

class Iterator {
private:
    //Const_iterator allows for easier debugging as const cant be changed.
	//variant allows for the iterator to be either a vector or a map
    variant<idVector::const_iterator, idMap::const_iterator> ptr;

public:
    explicit Iterator(idVector::const_iterator p) : ptr(p) {}

    // Required for range-based for: dereference
    const string& operator*() { return *get<idVector::const_iterator>(ptr); }

    // Required for range-based for: inequality comparison
    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }

    // Required for range-based for: pre-increment
    Iterator& operator++();
};

class idManager {
private:
    idStorage Storage;

public:
    idManager();
    idManager(idType Type);
    string operator[](const string ID);
    void operator+=(const string ID);
    void operator-=(const string ID);


   
    Iterator begin();
    Iterator end();
};
