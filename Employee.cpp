#include "Employee.h"

//Desc: creates a new object of type Employee
//In: -
//Out: a new object of type Employee with implicit values
Employee::Employee(){
	this->id = 0;
	this->name = "";
	this->email = "";
	this->accessDegree = 0;
}

//Desc: creates a new object of type Employee
//In: id, string - the id to be given to the new object
//    name, string - the name to be given to the new object
//    email, string - the email to be given to the new object
//	  accessDegree, int - the access degree to be given to the new object
//Out: a new object of type Employee with values given by this parameters
Employee::Employee(int id, string name, string email, int accessDegree){
	this->id = id;
	this->name = name;
	this->email = email;
	this->accessDegree = accessDegree;
}

//Desc: creates a new object of type Employee
//In: emp, const Employee& - an object of type Employee
//Out: a new object of type Employee with values given by the object in parameters
Employee::Employee(const Employee& emp){
	this->id = emp.id;
	this->name = emp.name;
	this->email = emp.email;
	this->accessDegree = emp.accessDegree;
}

//Desc: creates a new object of type Employee
//In:
//Out:
Employee::Employee(string line, char delim) {
	vector<string> words = split(line, delim);
	this->id = stoi(words[0]);
	this->name = words[1];
	this->email = words[2];
	this->accessDegree = stoi(words[3]);
}

//Desc: destroys an object of type Employee
//In: -
//Out -
Employee::~Employee()
{
}

//Desc: sets a new id to the current object
//In: id, int - the new id
//Out: -
void Employee::setID(int id) {
	this->id = id;
}

//Desc: sets a new name to the current object
//In: name, string - the new name
//Out: -
void Employee::setName(string name) {
	this->name = name;
}

//Desc: sets a new email to the current object
//In: email, string - the new email
//Out: -
void Employee::setEmail(string email) {
	this->email = email;
}

//Desc: sets a new acess degree to the current object
//In: acessDegree, string - the new acess degree
//Out: -
void Employee::setDegree(int accessDegree) {
	this->accessDegree = accessDegree;
}

//Desc: access the id of the current object
//In: -
//Out: the object's id
int Employee::getID() const {
	return this->id;
}

//Desc: access the name of the current object
//In: -
//Out: the object's name
string Employee::getName() const {
	return this->name;
}

//Desc: access the email of the current object
//In: -
//Out: the object's email
string Employee::getEmail() const {
	return this->email;
}

//Desc: access the access degree of the current object
//In: -
//Out: the object's access degree
int Employee::getDegree() const {
	return this->accessDegree;
}

//Desc: associates new values to the current object
//In: emp, const Employee& - an object of type Employee
//Out: the current instance with emp's values
Employee& Employee::operator=(const Employee& emp) {
	if (this != &emp) {
		this->id = emp.id;
		this->name = emp.name;
		this->email = emp.email;
		this->accessDegree = emp.accessDegree;
	}

	return *this;
}

//Desc: checks if the objects are equal
//In: e, const Employee& - an object of type Employee
//Out: true/false
bool Employee::operator==(const Employee& e) {
	return (this->id == e.id && this->name == e.name &&
		this->email == e.email && this->accessDegree == e.accessDegree);
}

//Desc: checks if the objects are equal
//In: e, const Employee& - an object of type Employee
//Out: true/false
bool Employee::operator!=(const Employee& e) {
	return (this->id != e.id || this->name != e.name ||
		this->email != e.email || this->accessDegree != e.accessDegree);
}

//Desc: creates a clone of the current object
//In: -
//Out: emp, Employee* - the clone of the current object
Employee* Employee::clone() {
	Employee* emp = new Employee(this->id, this->name, this->email, this->accessDegree);

	return emp;
}

//Desc: check if current object has the same values with another object
//In: ent, Employee* - the object to check the equality with
//Out: true/false
bool Employee::equals(Employee* ent) {
	return ((this->id == ent->id) && (this->name == ent->name) &&
		(this->email == ent->email) && (this->accessDegree == ent->accessDegree));
}

//Desc: turns current object into a string with values separated by a delimiter
//In: del, string - the delimiter
//Out: string with current object's values separated by del
string Employee::toString(string del) {
	string obj = "";

	obj = obj + to_string(this->id) + del + this->name + del + this->email + del +
		to_string(this->accessDegree);

	return obj;
}

//Desc: reads an employee via standard input stream
//In: is, istream& - a reference to an input stream
//    emp, Employee& - the employee
//Out: is, a reference to the input stream
istream& operator>>(istream& is, Employee& emp) {
	is >> emp.id;
	is >> emp.name;
	is >> emp.email;
	is >> emp.accessDegree;

	return is;
}