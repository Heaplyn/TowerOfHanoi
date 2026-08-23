#pragma once
#include <string>

using namespace std;

const char CHAR_RANGE[][2] = { {'A', 'Z'}, {'a', 'z'}, {'0', '9'} };
const int DEFAULT_CHARS = 7;
const int CHAR_DEFAULT = 0;

string GenerateRandomString(int Characters = DEFAULT_CHARS);
string DetermineDiskName(int weight = CHAR_DEFAULT);