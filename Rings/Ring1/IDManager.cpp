#include "IDManager.h"

template <typename vectorType>
int FindVector(const vector<vectorType>& CurrentVector, const vectorType& Value) {
    for (int i = 0; i < (int)CurrentVector.size(); i++) {
        if (CurrentVector.at(i) == Value) {
            return i;
        }
    }
    return -1;
}

void idManager::operator-=(const string ID) {
    if (holds_alternative<idMap>(Storage)) {
        get<idMap>(Storage).erase(ID);
    }
    else if (holds_alternative<idVector>(Storage)) {
        idVector& NewStorage = get<idVector>(Storage);
        int FoundIndex = FindVector<string>(NewStorage, ID);
        if (FoundIndex != -1) {
            NewStorage.erase(NewStorage.begin() + FoundIndex);
        }
    }
}

idManager::idManager() : idManager(Map) {}

idManager::idManager(idType Type) {
    switch (Type) {
        case Vector:
            Storage = idVector();
            break;
        default:
            Storage = idMap();
            break;
    }
}

string idManager::operator[](const string ID) {
    if (holds_alternative<idMap>(Storage)) {
        auto& m = get<idMap>(Storage);
        if (m.count(ID)) return ID;
    }
    else if (holds_alternative<idVector>(Storage)) {
        auto& v = get<idVector>(Storage);
        for (const auto& s : v) {
            if (s == ID) return s;
        }
    }
    return "";
}

void idManager::operator+=(const string ID) {
    if (holds_alternative<idMap>(Storage)) {
        get<idMap>(Storage)[ID] = true;
    }
    else if (holds_alternative<idVector>(Storage)) {
        get<idVector>(Storage).push_back(ID);
    }
}
