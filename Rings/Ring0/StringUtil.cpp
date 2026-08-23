/*
Heaplyn, 8/20/26
List of string utils
*/

#include "StringUtil.h"

int SizeDimension1 = sizeof(CHAR_RANGE) / sizeof(CHAR_RANGE[0]);

char GetRandomBetween(const char Range[2]) {
    char MinChar = Range[0];
    char MaxChar = Range[1];
    // 1 needs to be here to align properly with the range
    char Span = (MaxChar - MinChar) + 1;
    return MinChar + (rand() % Span);
}

char GenerateRandomChar() {
    int ChosenNum = rand() % SizeDimension1;

    // & passes by reference, making it less memory intensive.
    const char(&ChosenArray)[2] = CHAR_RANGE[ChosenNum];

    return GetRandomBetween(ChosenArray);
}

string GenerateRandomString(int Characters) {
    string ReturnedString = "";
    for (int i = 0; i < Characters; i++) {
        ReturnedString += GenerateRandomChar();
    }
    return ReturnedString;
}

int GetBaseSize() {
    int total = 0;
    for (int i = 0; i < SizeDimension1; i++) {
        total += (CHAR_RANGE[i][1] - CHAR_RANGE[i][0]) + 1;
    }
    return total;
}

char GetCharFromIndex(int index) {
    int temp = index;
    for (int i = 0; i < SizeDimension1; i++) {
        int span = (CHAR_RANGE[i][1] - CHAR_RANGE[i][0]) + 1;
        if (temp < span) {
            return CHAR_RANGE[i][0] + temp;
        }
        temp -= span;
    }
    return 'A'; // Fallback
}

string DetermineDiskName(int weight) {
    
    int base = GetBaseSize();
    string name = "";
    int temp = weight - 1;
    
    while (temp >= 0) {
        name = GetCharFromIndex(temp % base) + name;
        temp = (temp / base) - 1;
    }
    return name;
}