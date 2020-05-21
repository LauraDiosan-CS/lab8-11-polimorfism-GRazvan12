#include "ValidatorConversieMedicament.h"

ValidatorConversieMedicament::ValidatorConversieMedicament()
{
}

ValidatorConversieMedicament::~ValidatorConversieMedicament()
{
}

void ValidatorConversieMedicament::validate(string id, string name, string prescription, string stockNr, string producer) {
	ValidationException v("");
	string str = "-0123456789";

	if (str.find(id[0]) == string::npos || id.substr(1).find_first_not_of("0123456789") != string::npos)
		v.addMessage("ID-ul nu poate fi convertit in numar intreg!\n");

	if (prescription != "0" && prescription != "1")
		v.addMessage("Necesitatea unei retete nu poate fi convertita ca bool!\n");

	if (str.find(stockNr[0]) == string::npos || stockNr.substr(1).find_first_not_of("0123456789") != string::npos)
		v.addMessage("Numarul medicamentelor din stoc nu poate fi convertit in numar intreg!\n");

	if (v.what() != "")
		throw v;
}