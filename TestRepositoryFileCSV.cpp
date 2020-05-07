#include "TestRepositoryFileCSV.h"

void TestRepositoryFileCSV::testAll() {
	this->testConsctructors();
	this->testSettersAndGetters();
	this->testFileFunctions();
}

//Desc: function to test the constructors of class RepositoryFileCSV
void TestRepositoryFileCSV::testConsctructors() {
	RepositoryFileCSV<Medicament> repo1;
	assert(repo1.getFileName() == "");
	RepositoryFileCSV<Medicament> repo("Test.txt");
	assert(repo.getFileName() == "Test.txt");

	RepositoryFileCSV<Medicament>* prepo1 = new RepositoryFileCSV<Medicament>();
	assert(prepo1->getFileName() == "");
	RepositoryFileCSV<Medicament>* prepo = new RepositoryFileCSV<Medicament>("Test.txt");
	assert(prepo->getFileName() == "Test.txt");

	delete prepo1;
	delete prepo;
}

//Desc: function to test the setters and getters of class RepositoryFileCSV
void TestRepositoryFileCSV::testSettersAndGetters() {
	RepositoryFileCSV<Employee> repo;
	assert(repo.getFileName() == "" && repo.getSize() == 0);
	repo.setFileName("Test.txt");
	assert(repo.getFileName() == "Test.txt");

	Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
	repo.add(e);
	assert(repo.getSize() == 1 && (*(repo.getElemPos(0)) == *e) == true);

	repo.empty();
	assert(repo.getSize() == 0);

	delete e;
}

//Desc: function to test the file function of class RepositoryFileTXT
void TestRepositoryFileCSV::testFileFunctions() {
	RepositoryFileCSV<Employee> repo("Test.txt");
	repo.loadFromFile();
	assert(repo.getSize() == 0);

	Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
	repo.add(e);
	repo.loadFromFile();
	assert(repo.getSize() == 1);

	repo.empty();

	delete e;
}