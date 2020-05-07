#include <iostream>
#include <fstream>
#include <string>
#include "TestIEntity.h"
#include "TestMedicament.h"
#include "TestEmployee.h"
#include "TestRepository.h"
#include "TestRepositoryFileTXT.h"
#include "TestRepositoryFileCSV.h"

using namespace std;

int main()
{
	TestIEntity testEnt;
	testEnt.testAll();
	TestMedicament testMed;
	testMed.testAll();
	TestEmployee testEmp;
	testEmp.testAll();
	TestRepository testFile;
	testFile.testAll();
	TestRepositoryFileTXT testTXT;
	testTXT.testAll();
	TestRepositoryFileCSV testCSV;
	testCSV.testAll();

	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	repo->add(m1);
	repo->add(m2);
	assert(repo->getAll().getSize() == 2);
	assert(*repo->getAll()[0] == *m1);
	assert(*repo->getAll()[1] == *m2);
	repo->add(m3);
	assert(*repo->getAll()[2] == *m3);

	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, &m1_new);
	assert(*repo->getAll()[0] != *m1);
	assert(*repo->getAll()[0] == m1_new);

	repo->remove(200);
	assert(repo->getSize() == 2);


	delete m1;
	delete m2;
	delete m3;
	return 0;
}