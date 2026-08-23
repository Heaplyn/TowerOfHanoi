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

Iterator& Iterator::operator++() {
	if (holds_alternative<idVector::const_iterator>(ptr)) {
		++get<idVector::const_iterator>(ptr);
	}
	else if (holds_alternative<idMap::const_iterator>(ptr)) {
		++get<idMap::const_iterator>(ptr);
	}
	return *this;
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

void idManager::operator+=(const string ID) {
    if (holds_alternative<idMap>(Storage)) {
        get<idMap>(Storage)[ID] = true;
    }
    else if (holds_alternative<idVector>(Storage)) {
        idVector& NewStorage = get<idVector>(Storage);
        int FoundIndex = FindVector<string>(NewStorage, ID);
        if (FoundIndex != -1) {
			return; // ID already exists, do nothing
        }
		NewStorage.push_back(ID);
    }
}

/*For the beginning bookmark of the storage thing
Think of an iterator like a page in a book. 
you have its address and you can move to n amount of pages or wtv
*/

//Beginning iterator
Iterator idManager::begin() {
    return Iterator(get<idVector>(Storage).begin());
}

//Ending iterator
Iterator idManager::end() {
    return Iterator(get<idVector>(Storage).end());
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
    //Basically is finding the ID in storage
    //If statement is checking if Storage is a map or vector
    if (holds_alternative<idMap>(Storage)) {
        idMap& m = get<idMap>(Storage);
        if (m.count(ID)) return ID;
    }
    else if (holds_alternative<idVector>(Storage)) {
        idVector& v = get<idVector>(Storage);
        for (const string& s : v) {
            if (s == ID) return s;
        }
    }
    return "";
}

