#include "TestMedicament.h"

//Desc: public member function to test all other functions
void TestMedicament::testAll() {
	this->testConstructors();
	this->testSettersAndGetters();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testClone();
	this->testEquals();
	this->testToString();
}

//Desc: function to test the constructors of class Medicament
void TestMedicament::testConstructors() {
	Medicament m1;
	assert(m1.getID() == 0 && m1.getName() == "" && m1.getPrescription() == false &&
		m1.getStockNr() == 0 && m1.getProducer() == "");
	Medicament m2(1, "nurofen", false, 100, "ungaria");
	assert(m2.getID() == 1 && m2.getName() == "nurofen" && m2.getPrescription() == false &&
		m2.getStockNr() == 100 && m2.getProducer() == "ungaria");
	Medicament m3(m2);
	assert(m3.getID() == 1 && m3.getName() == "nurofen" && m3.getPrescription() == false &&
		m3.getStockNr() == 100 && m3.getProducer() == "ungaria");


	Medicament *pm1 = new Medicament();
	assert(pm1->getID() == 0 && pm1->getName() == "" && pm1->getPrescription() == false &&
		pm1->getStockNr() == 0 && pm1->getProducer() == "");
	Medicament* pm2 = new Medicament(2, "paracetamol", true, 12, "nimeni");
	assert(pm2->getID() == 2 && pm2->getName() == "paracetamol" && pm2->getPrescription() == true &&
		pm2->getStockNr() == 12 && pm2->getProducer() == "nimeni");
	Medicament* pm3 = new Medicament(*pm2);
	assert(pm3->getID() == 2 && pm3->getName() == "paracetamol" && pm3->getPrescription() == true &&
		pm3->getStockNr() == 12 && pm3->getProducer() == "nimeni");

	delete pm1;
	delete pm2;
	delete pm3;
}

//Desc: function to test the setters and getters of class Medicament
void TestMedicament::testSettersAndGetters() {
	Medicament m;
	assert(m.getID() == 0 && m.getName() == "" && m.getPrescription() == false &&
		m.getStockNr() == 0 && m.getProducer() == "");

	m.setID(1);
	m.setName("nurofen");
	m.setPrescription(true);
	m.setStockNr(133);
	m.setProducer("romania");

	assert(m.getID() == 1 && m.getName() == "nurofen" && m.getPrescription() == true &&
		m.getStockNr() == 133 && m.getProducer() == "romania");
}

//Desc: function to test the assignment operator of class Medicament
void TestMedicament::testAssignmentOperator() {
	Medicament m1(6, "algocalmin", true, 456, "rusia");
	Medicament m2;
	assert(m2.getID() == 0 && m2.getName() == "" && m2.getPrescription() == false &&
		m2.getStockNr() == 0 && m2.getProducer() == "");

	m2 = m1;

	assert(m2.getID() == 6 && m2.getName() == "algocalmin" && m2.getPrescription() == true &&
		m2.getStockNr() == 456 && m2.getProducer() == "rusia");
}

//Desc: function to test the equality operator of class Medicament
void TestMedicament::testEqualityOperator() {
	Medicament m1(6, "algocalmin", true, 456, "rusia");
	Medicament m2(1, "nurofen", false, 100, "ungaria");

	assert((m1 == m2) == false);
}

//Desc: function to test the clone function of class Medicament
void TestMedicament::testClone() {
	Medicament m(6, "algocalmin", true, 456, "rusia");
	Medicament* pm2 = (Medicament*)m.clone();

	assert(pm2->getID() == 6 && pm2->getName() == "algocalmin" && pm2->getPrescription() == true &&
		pm2->getStockNr() == 456 && pm2->getProducer() == "rusia");

	delete pm2;
}

//Desc: function to test the equals function of class Medicament
void TestMedicament::testEquals() {
	Medicament* m1 = new Medicament(6, "algocalmin", true, 456, "rusia");
	Medicament* m2 = new Medicament(1, "nurofen", false, 100, "ungaria");

	assert(m1->equals(m2) == false);

	delete m1;
	delete m2;
}

//Desc: function to test the to string function of class Medicament
void TestMedicament::testToString() {
	Medicament m(1, "nurofen", false, 100, "ungaria");
	string s = m.toString(",");

	assert(s == "M,1,nurofen,0,100,ungaria");
}