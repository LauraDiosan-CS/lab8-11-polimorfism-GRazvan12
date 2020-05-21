#include "TestRepository.h"
#include "TestRepositoryFileCSV.h"
#include "TestRepositoryFileTXT.h"
#include "TestEmployee.h"
#include "TestMedicament.h"
#include "TestServiceEmployee.h"
#include "TestServiceMedicine.h"
#include "MyException.h"
#include "UI.h"

using namespace std;

int main()
{
	srand(time(NULL));

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
	TestServiceMedicine testServMed;
	testServMed.testAll();
	TestServiceEmployee testServEmp;
	testServEmp.testAll();
	
	
	/*
	bool goNext = false;
	string answer = "";
	Repository<Employee>* repoEmp = NULL;
	Repository<Medicament>* repoMed = NULL;
	int number = 0;
	
	while (goNext == false) {
		cout << "Introduceti numarul tipului de fisier dorit:\n";
		cout << "\t1. Fisier TXT\n";
		cout << "\t2. Fisier CSV\n";
		cout << "Numarul ales: ";
		getline(cin, answer);

		try {
			number = stoi(answer);
			if (number != 1 && number != 2)
				throw exception();
			goNext = true;
		}
		catch (...) {
			cout << "Numarul trebuie sa fie 1 sau 2!\n";
		}
	}
	
	if (number == 1) {
		repoEmp = new RepositoryFileTXT<Employee>("Employee.txt");
		repoMed = new RepositoryFileTXT<Medicament>("Medicament.txt");
	}
	else {
		repoEmp = new RepositoryFileCSV<Employee>("Employee.csv");
		repoMed = new RepositoryFileCSV<Medicament>("Medicament.csv");
	}

	ServiceEmployee* servEmp = new ServiceEmployee(repoEmp);
	ServiceMedicine* servMed = new ServiceMedicine(repoMed);

	UI ui(servEmp, servMed);
	ui.runUI();*/

	return 0;
}