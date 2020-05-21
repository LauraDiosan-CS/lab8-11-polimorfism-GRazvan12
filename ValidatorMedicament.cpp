#include "ValidatorMedicament.h"

ValidatorMedicament::ValidatorMedicament()
{
}

ValidatorMedicament::~ValidatorMedicament()
{
}

void ValidatorMedicament::validate(Medicament* med) {
	ValidationException v("");

	if (med->getID() < 0)
		v.addMessage("ID-ul trebuie sa fie strict pozitiv!\n");

	if (med->getStockNr() < 0)
		v.addMessage("Numarul medicamentelor de pe stoc trebuie sa fie strict pozitiv!\n");

	if (v.what() != "")
		throw v;
}