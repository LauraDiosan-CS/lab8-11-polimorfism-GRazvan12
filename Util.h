#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "MyException.h"

using namespace std;

static const char pool[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789";

static int poolSize = sizeof(pool) - 1;

vector<string> inline split(const string& s, char delim) {
	vector<string> words;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		words.push_back(item);

	return words;
}

void inline string_to_int(string nr) {
	string str = "-0123456789";

	if (str.find(nr[0]) == string::npos || nr.substr(1).find_first_not_of("0123456789") != string::npos)
		throw MyException("Numarul nu poate fi convertit in numar intreg!");
}

inline int getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

inline char getRandomChar() {
	return pool[rand() % poolSize];
}