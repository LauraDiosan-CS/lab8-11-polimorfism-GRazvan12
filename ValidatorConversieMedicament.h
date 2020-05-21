#pragma once
#include <iostream>
#include "ValidationException.h"

using namespace std;

class ValidatorConversieMedicament {
public:
	ValidatorConversieMedicament();
	~ValidatorConversieMedicament();
	void validate(string, string, string, string, string);
};