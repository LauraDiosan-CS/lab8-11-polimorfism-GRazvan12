#include "TestServiceEmployee.h"

void TestServiceEmployee::testAll() {
	this->testConstructors();
	this->testGetters();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
	this->testCheckUser();
}

void TestServiceEmployee::testConstructors() {
	Repository<Employee>* repo = new RepositoryFileTXT<Employee>();
	ServiceEmployee serv(repo);
	assert(serv.getSize() == 0);
}

void TestServiceEmployee::testGetters() {
	Repository<Employee>* repo = new RepositoryFileTXT<Employee>();
	ServiceEmployee serv;
	Employee emp(1, "gicu", "gicu@utcn", 134);
	try {
		repo->add(&emp);

		serv.setRepo(repo);
		Employee* empTest = serv.getElemPos(0);
		assert(serv.getSize() == 1 && empTest->equals(&emp));

		delete empTest;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void TestServiceEmployee::testAdd() {
	Repository<Employee>* repo = new RepositoryFileTXT<Employee>();
	ServiceEmployee serv(repo);

	Employee emp(1, "nicu", "nicu@ubb", 12);
	try {
		serv.add(1, "nicu", "nicu@ubb", 12);

		Employee* empTest = serv.getElemPos(0);
		assert(serv.getSize() == 1 && empTest->equals(&emp));

		delete empTest;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void TestServiceEmployee::testDelete() {
	Repository<Employee>* repo = new RepositoryFileTXT<Employee>();
	ServiceEmployee serv(repo);
	try {
		serv.add(1, "nicu", "nicu@ubb", 12);

		assert(serv.getSize() == 1);
		serv.remove(1);
		assert(serv.getSize() == 0);
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void TestServiceEmployee::testUpdate() {
	Repository<Employee>* repo = new RepositoryFileTXT<Employee>();
	ServiceEmployee serv(repo);
	serv.add(1, "nicu", "nicu@ubb", 12);

	assert(serv.getSize() == 1);
	try {
		serv.update(1, "drojdierul", "drojdierul@gmail", 144);
		Employee emp(1, "drojdierul", "drojdierul@gmail", 144);

		Employee* empTest = serv.getElemPos(0);
		assert(empTest->equals(&emp));

		delete empTest;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void TestServiceEmployee::testCheckUser() {
	Repository<Employee>* repo = new RepositoryFileTXT<Employee>();
	ServiceEmployee serv(repo);
	serv.add(1, "nicu", "nicu@ubb", 12);

	assert(serv.checkUser("nicu@ubb", "nicu") == true);
	assert(serv.checkUser("gicu@utcn", "gicu") == false);
}