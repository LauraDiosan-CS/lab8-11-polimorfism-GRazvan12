#include "TestRepository.h"

void TestRepository::testAll() {
	this->testConsctructors();
	this->testSettersAndGetters();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
}

//Desc: function to test the constructors of class Repository
void TestRepository::testConsctructors() {
	Repository<Employee> repo1;
	assert(repo1.getFileName() == "");
	Repository<Employee> repo("Test.txt");
	assert(repo.getFileName() == "Test.txt");

	Repository<Employee>* prepo1 = new Repository<Employee>();
	assert(prepo1->getFileName() == "");
	Repository<Employee>* prepo = new Repository<Employee>("Test.txt");
	assert(prepo->getFileName() == "Test.txt");

	delete prepo1;
	delete prepo;
}

//Desc: function to test the setters and getters of class Repository
void TestRepository::testSettersAndGetters() {
	Repository<Employee> repo;
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

//Desc: function to test the adding of an element in Repo
void TestRepository::testAdd() {
	Repository<Employee> repo;
	assert(repo.getSize() == 0);

	Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
	repo.add(e);
	assert(repo.getSize() == 1);

	delete e;
}

//Desc: function to test the delete of an element function in Repo
void TestRepository::testDelete() {
	Repository<Employee> repo;
	assert(repo.getSize() == 0);

	Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
	repo.add(e);
	assert(repo.getSize() == 1);

	//repo.remove(e);
	//assert(repo.getSize() == 0);

	delete e;
}

//Desc: function to test the updateof an element function in Repo
void TestRepository::testUpdate() {
	Repository<Employee> repo;
	assert(repo.getSize() == 0);

	Employee* e1 = new Employee(1, "nicu", "nicu@ubb", 4);
	Employee* e2 = new Employee(2, "gicu", "gicu@ubb", 15);
	repo.add(e1);
	assert(repo.getSize() == 1);

	repo.update(e1, e2);
	assert(*(repo.getElemPos(0)) == *e2);

	delete e1;
	delete e2;
}