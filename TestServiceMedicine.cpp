#include "TestServiceMedicine.h"

void TestServiceMedicine::testAll() {
	this->testConstructors();
	this->testGetters();
	this->testAdd();
	this->testDelete();
	this->testUpdate();
	this->cerintaService();
}

void TestServiceMedicine::testConstructors() {
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	ServiceMedicine serv(repo);
	assert(serv.getSize() == 0);
}

void TestServiceMedicine::testGetters() {
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	ServiceMedicine serv;
	Medicament med(1, "xanax", false, 122, "columbia");
	repo->add(&med);

	serv.setRepo(repo);
	Medicament* medTest = serv.getElemPos(0);
	assert(serv.getSize() == 1 && medTest->equals(&med));

	delete medTest;
}

void TestServiceMedicine::testAdd() {
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	ServiceMedicine serv(repo);

	Medicament med(1, "xanax", false, 122, "columbia");
	serv.add(1, "xanax", false, 122, "columbia");

	Medicament* medTest = serv.getElemPos(0);
	assert(serv.getSize() == 1 && medTest->equals(&med));

	delete medTest;
}

void TestServiceMedicine::testDelete() {
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	ServiceMedicine serv(repo);
	serv.add(1, "xanax", false, 122, "columbia");

	assert(serv.getSize() == 1);
	serv.remove(1);
	assert(serv.getSize() == 0);
}

void TestServiceMedicine::testUpdate() {
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	ServiceMedicine serv(repo);
	serv.add(1, "xanax", false, 122, "columbia");

	assert(serv.getSize() == 1);
	serv.update(1, "nurofen", true, 144, "romania");
	Medicament med(1, "nurofen", true, 144, "romania");

	Medicament* medTest = serv.getElemPos(0);
	assert(medTest->equals(&med));

	delete medTest;
}

void TestServiceMedicine::cerintaService() {
	Repository<Medicament>* repository = new RepositoryFileTXT<Medicament>();
	ServiceMedicine* service = new ServiceMedicine(repository);
	Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	service->add(m1);
	service->add(m2);
	assert(service->getAll().size() == 2);
	assert(*service->getAll()[0] == *m1);
	assert(*service->getAll()[1] == *m2);
	service->add(m3);
	assert(*service->getAll()[2] == *m3);

	assert(service->search("ic").size() == 1);
	assert(service->search("a").size() == 3);

	Medicament m1_new(100, "altceva", false, 50, "p1");
	service->update(m1, &m1_new);
	assert(service->search("al").size() == 2);
	assert(*service->search("al")[0] == m1_new);
	assert(*service->search("al")[1] == *m2);
	service->remove(200);
	assert(service->search("al").size() == 1);
	assert(*service->search("al")[0] == m1_new);

	delete m1;
	delete m2;
	delete m3;
}