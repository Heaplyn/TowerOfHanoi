#pragma once

#include <string>
#include <random>
#include <iostream>

using namespace std;

const char CHAR_RANGE[][2] = { {'A','Z'},{'a','z'},{'0','9'}};
const int DEFAULT_CHARS = 7;

string GenerateRandomString(int Characters = DEFAULT_CHARS);
