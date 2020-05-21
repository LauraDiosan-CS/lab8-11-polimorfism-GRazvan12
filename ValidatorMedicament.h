#pragma once
#include <iostream>
#include "ValidationException.h"
#include "Medicament.h"

using namespace std;

class ValidatorMedicament {
public:
	ValidatorMedicament();
	~ValidatorMedicament();
	void validate(Medicament*);
};