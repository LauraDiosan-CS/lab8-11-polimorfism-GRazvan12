#include "ValidatorConversieEmployee.h"

ValidatorConversieEmployee::ValidatorConversieEmployee()
{
}

ValidatorConversieEmployee::~ValidatorConversieEmployee()
{
}

void ValidatorConversieEmployee::validate(string id, string name, string email, string accessDegree) {
	ValidationException v("");
	string str = "-0123456789";

	if (str.find(id[0]) == string::npos || id.substr(1).find_first_not_of("0123456789") != string::npos)
		v.addMessage("ID-ul nu poate fi convertit in numar intreg!\n");

	if (str.find(accessDegree[0]) == string::npos || accessDegree.substr(1).find_first_not_of("0123456789") != string::npos)
		v.addMessage("Gradul de acces nu poate fi convertit in numar intreg!\n");

	if (v.what() != "")
		throw v;
}