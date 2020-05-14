#include "TestRepository.h"

void TestRepository::testAll() {
	this->testConsctructors();
	this->testSettersAndGetters();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
	this->testCerinta1();
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
	try {
		Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
		repo.add(e);
		assert(repo.getSize() == 1 && (*(repo.getElemPos(0)) == *e) == true);

		repo.empty();
		assert(repo.getSize() == 0);

		delete e;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

//Desc: function to test the adding of an element in Repo
void TestRepository::testAdd() {
	Repository<Employee> repo;
	assert(repo.getSize() == 0);
	try {
		Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
		repo.add(e);
		assert(repo.getSize() == 1);

		delete e;
	}
	catch (MyException& exc) {
		cout << exc.what();
	}
}

//Desc: function to test the delete of an element function in Repo
void TestRepository::testDelete() {
	Repository<Employee> repo;
	assert(repo.getSize() == 0);
	try {
		Employee* e = new Employee(1, "nicu", "nicu@ubb", 4);
		repo.add(e);
		assert(repo.getSize() == 1);

		//repo.remove(e);
		//assert(repo.getSize() == 0);

		delete e;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

//Desc: function to test the updateof an element function in Repo
void TestRepository::testUpdate() {
	Repository<Employee> repo;
	assert(repo.getSize() == 0);
	try {
		Employee* e1 = new Employee(1, "nicu", "nicu@ubb", 4);
		Employee* e2 = new Employee(2, "gicu", "gicu@ubb", 15);
		repo.add(e1);
		assert(repo.getSize() == 1);

		repo.update(e1, e2);
		assert(*(repo.getElemPos(0)) == *e2);

		delete e1;
		delete e2;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}

void TestRepository::testCerinta1() {
	try {
		Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
		Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
		Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
		Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

		repo->add(m1);
		repo->add(m2);
		assert(repo->getAll().size() == 2);
		assert(*repo->getAll()[0] == *m1);
		assert(*repo->getAll()[1] == *m2);
		repo->add(m3);
		assert(*repo->getAll()[2] == *m3);

		Medicament m1_new(100, "paracetamol", false, 50, "p1");
		repo->update(m1, &m1_new);
		assert(*repo->getAll()[0] != *m1);
		assert(*repo->getAll()[0] == m1_new);

		repo->remove(200);
		assert(repo->getAll().size() == 2);


		delete m1;
		delete m2;
		delete m3;
		delete repo;
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
}