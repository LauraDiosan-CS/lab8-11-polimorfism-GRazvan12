#include "TestEmployee.h"

//Desc: public member function to test all other functions
void TestEmployee::testAll() {
	this->testConstructors();
	this->testSettersAndGetters();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testClone();
	this->testEquals();
	this->testToString();
}

//Desc: function to test the constructors of class Employee
void TestEmployee::testConstructors() {
	Employee e1;
	assert(e1.getID() == 0 && e1.getName() == "" && e1.getEmail() == "" &&
		e1.getDegree() == 0);
	Employee e2(1, "nicu", "nicu@ubb", -1);
	assert(e2.getID() == 1 && e2.getName() == "nicu" && e2.getEmail() == "nicu@ubb" &&
		e2.getDegree() == -1);
	Employee e3(e2);
	assert(e3.getID() == 1 && e3.getName() == "nicu" && e3.getEmail() == "nicu@ubb" &&
		e3.getDegree() == -1);

	Employee* pe1 = new Employee();
	assert(pe1->getID() == 0 && pe1->getName() == "" && pe1->getEmail() == "" &&
		pe1->getDegree() == 0);
	Employee* pe2 = new Employee(2, "peste", "peste@romania", 14);
	assert(pe2->getID() == 2 && pe2->getName() == "peste" &&
		pe2->getEmail() == "peste@romania" && pe2->getDegree() == 14);
	Employee* pe3 = new Employee(*pe2);
	assert(pe3->getID() == 2 && pe3->getName() == "peste" &&
		pe3->getEmail() == "peste@romania" && pe3->getDegree() == 14);

	delete pe1;
	delete pe2;
	delete pe3;
}

//Desc: function to test the setters and getters of class Employee
void TestEmployee::testSettersAndGetters() {
	Employee e;
	assert(e.getID() == 0 && e.getName() == "" && e.getEmail() == "" &&
		e.getDegree() == 0);

	e.setID(1);
	e.setName("porodica");
	e.setEmail("porodica@ubb");
	e.setDegree(99);

	assert(e.getID() == 1 && e.getName() == "porodica" && 
		e.getEmail() == "porodica@ubb" && e.getDegree() == 99);
}

//Desc: function to test the assignment operator of class Medicament
void TestEmployee::testAssignmentOperator() {
	Employee e(1, "nicu", "nicu@ubb", -1);
	Employee e2;
	assert(e2.getID() == 0 && e2.getName() == "" && e2.getEmail() == "" &&
		e2.getDegree() == 0);

	e2 = e;
	assert(e2.getID() == 1 && e2.getName() == "nicu" && e2.getEmail() == "nicu@ubb" &&
		e2.getDegree() == -1);
}

//Desc: function to test the equality operator of class Employee
void TestEmployee::testEqualityOperator() {
	Employee e(1, "nicu", "nicu@ubb", -1);
	Employee e2(1, "nicu", "nicu@ubb", -1);

	assert((e == e2) == true);
}

//Desc: function to test the clone function of class Employee
void TestEmployee::testClone() {
	Employee e(1, "nicu", "nicu@ubb", -1);
	Employee* pe2 = (Employee*)e.clone();

	assert(pe2->getID() == 1 && pe2->getName() == "nicu" &&
		pe2->getEmail() == "nicu@ubb" && pe2->getDegree() == -1);
}

//Desc: function to test the equals function of class Employee
void TestEmployee::testEquals() {
	Employee* pe1 = new Employee(1, "nicu", "nicu@ubb", -1);
	Employee* pe2 = new Employee(1, "nicu", "nicu@ubb", -1);

	assert(pe1->equals(pe2) == true);

	delete pe1;
	delete pe2;
}

//Desc: function to test the to string function of class Employee
void TestEmployee::testToString() {
	Employee e(1, "nicu", "nicu@ubb", -1);
	string s = e.toString(",");

	assert(s == "E,1,nicu,nicu@ubb,-1");
}