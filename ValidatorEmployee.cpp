#include "ValidatorEmployee.h"

ValidatorEmployee::ValidatorEmployee()
{
}

ValidatorEmployee::~ValidatorEmployee()
{
}

void ValidatorEmployee::validate(Employee* emp) {
	ValidationException v("");

	if (emp->getID() < 0)
		v.addMessage("ID-ul trebuie sa fie strict pozitiv!\n");

	//if (emp->getName().find_first_of("0123456789") != string::npos)
		//v.addMessage("Numele nu poate contine cifre!\n");

	//if (emp->getEmail().find("@") == string::npos)
		//v.addMessage("Email-ul nu poate fi valid fara caracterul \"@\"!\n");

	if (emp->getDegree() < 0)
		v.addMessage("Gradul de acces trebuie sa fie strict pozitiv!\n");

	if (v.what() != "")
		throw v;
}