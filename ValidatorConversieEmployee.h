#pragma once
#include <iostream>
#include "ValidationException.h"

using namespace std;

class ValidatorConversieEmployee {
public:
	ValidatorConversieEmployee();
	~ValidatorConversieEmployee();
	void validate(string, string, string, string);
};