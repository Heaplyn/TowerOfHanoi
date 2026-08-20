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

class idManager {
private:
    idStorage Storage;

public:
    idManager();
    idManager(idType Type);
    string operator[](const string ID);
    void operator+=(const string ID);
    void operator-=(const string ID);
};
