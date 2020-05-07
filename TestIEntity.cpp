#include "TestIEntity.h"

//Desc: public member function to test all other functions
void TestIEntity::testAll() {
	this->testConstructors();
	this->testSettersAndGetters();
	this->testClone();
	this->testEquals();
	this->testToString();
}

//Desc: function to test the constructors of class IEntity
void TestIEntity::testConstructors() {
	IEntity e1;
	assert(e1.getID() == 0 && e1.getName() == "");
	IEntity e2(1, "nicu");
	assert(e2.getID() == 1 && e2.getName() == "nicu");
	IEntity e3(e2);
	assert(e3.getID() == 1 && e3.getName() == "nicu");

	IEntity* pe1 = new IEntity();
	assert(pe1->getID() == 0 && pe1->getName() == "");
	IEntity* pe2 = new IEntity(2, "peste");
	assert(pe2->getID() == 2 && pe2->getName() == "peste");
	IEntity* pe3 = new IEntity(*pe2);
	assert(pe3->getID() == 2 && pe3->getName() == "peste");

	delete pe1;
	delete pe2;
	delete pe3;
}

//Desc: function to test the setters and getters of class IEntity
void TestIEntity::testSettersAndGetters() {
	IEntity e;
	assert(e.getID() == 0 && e.getName() == "");

	e.setID(1);
	e.setName("porodica");

	assert(e.getID() == 1 && e.getName() == "porodica");
}

//Desc: function to test the clone function of class IEntity
void TestIEntity::testClone() {
	IEntity e(1, "nicu");
	IEntity* pe2 = e.clone();

	assert(pe2->getID() == 1 && pe2->getName() == "nicu");
}

//Desc: function to test the equals function of class IEntity
void TestIEntity::testEquals() {
	IEntity* pe1 = new IEntity(1, "nicu");
	IEntity* pe2 = new IEntity(1, "nicu");

	assert(pe1->equals(pe2) == true);

	delete pe1;
	delete pe2;
}

//Desc: function to test the to string function of class IEntity
void TestIEntity::testToString() {
	IEntity e(1, "nicu");
	string s = e.toString(",");

	assert(s == "1,nicu");
}