#include "TestRepositoryFileTXT.h"

void TestRepositoryFileTXT::testAll() {
	this->testConsctructors();
	this->testSettersAndGetters();
	this->testFileFunctions();
}

//Desc: function to test the constructors of class RepositoryFileTXT
void TestRepositoryFileTXT::testConsctructors() {
	RepositoryFileTXT<Employee> repo1;
	assert(repo1.getFileName() == "");
	RepositoryFileTXT<Employee> repo("Test.txt");
	assert(repo.getFileName() == "Test.txt");

	RepositoryFileTXT<Employee>* prepo1 = new RepositoryFileTXT<Employee>();
	assert(prepo1->getFileName() == "");
	RepositoryFileTXT<Employee>* prepo = new RepositoryFileTXT<Employee>("Test.txt");
	assert(prepo->getFileName() == "Test.txt");

	delete prepo1;
	delete prepo;
}

//Desc: function to test the setters and getters of class RepositoryFileTXT
void TestRepositoryFileTXT::testSettersAndGetters() {
	RepositoryFileTXT<Employee> repo;
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
void TestRepositoryFileTXT::testFileFunctions() {
	RepositoryFileTXT<Employee> repo("Test.txt");
	repo.loadFromFile();
	assert(repo.getSize() == 0);

	Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
	repo.add(e);
	assert(repo.getSize() == 1);

	repo.empty();

	delete e;
}