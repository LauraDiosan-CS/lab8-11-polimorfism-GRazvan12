#include "TestServiceEmployee.h"

void TestServiceEmployee::testAll() {
	this->testConstructors();
	this->testGetters();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
	this->testCheckUser();
	//this->testRandomGenerator();
}

void TestServiceEmployee::testConstructors() {
	for (int i = 0; i <= 100000; i++)
		for (int j = 0; j <= 10000; j++);
	
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
	assert(serv.checkUser("nicu@utcn", "gicu") == false);
}

void TestServiceEmployee::testRandomGenerator() {
	int nrAngajati = getRandomNumber(100, 200);
	int lungimeRandom;
	int nrRandom;
	Repository<Employee>* repo = new RepositoryFileTXT<Employee>();
	ServiceEmployee serv(repo);

	int id, degree;
	string name = "", email = "";

	for (int i = 1; i <= nrAngajati; i++) {
		id = rand() % 10000;
		degree = rand() & 5000;
		
		lungimeRandom = 1 + rand() % 10;

		for (int j = 0; j < lungimeRandom; j++)
			name += getRandomChar();

		lungimeRandom = 1 + rand() % 10;

		for (int j = 0; j < lungimeRandom; j++)
			email += getRandomChar();

		serv.add(id, name, email, degree);

		name = "";
		email = "";
	}

	Employee* emp;
	Employee* emp2;

	for (int i = 1; i <= 1000; i++) {
		nrRandom = rand() % nrAngajati;
		emp = serv.getElemPos(nrRandom);

		assert(serv.checkUser(emp->getEmail(), emp->getName()) == true);

		nrRandom = rand() % nrAngajati;

		emp2 = serv.getElemPos(nrRandom);

		if (emp->getDegree() > emp2->getDegree()) {
			assert(serv.modifyAccessDegree(emp->getEmail(), emp2->getID(), rand() % 5000) == true);
		}
		else {
			assert(serv.modifyAccessDegree(emp->getEmail(), emp2->getID(), rand() % 5000) == false);
		}

		delete emp;
		emp = NULL;
		delete emp2;
		emp2 = NULL;
	}
}