#pragma once
#include <iostream>
#include "ValidationException.h"
#include "Employee.h"

using namespace std;

class ValidatorEmployee {
public:
	ValidatorEmployee();
	~ValidatorEmployee();
	void validate(Employee*);
};