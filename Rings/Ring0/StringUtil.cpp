/*
Heaplyn, 8/20/26
List of string utils
*/

#include "StringUtil.h"

char GetRandomBetween(const char Range[2]) {
    char MinChar = Range[0];
    char MaxChar = Range[1];
    // 1 needs to be here to align properly with the range
    char Span = (MaxChar - MinChar) + 1;
    return MinChar + (rand() % Span);
}

char GenerateRandomChar() {
    int SizeDimension1 = sizeof(CHAR_RANGE) / sizeof(CHAR_RANGE[0]);
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
