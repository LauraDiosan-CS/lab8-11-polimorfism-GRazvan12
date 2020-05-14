#pragma once
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"

using namespace std;

class ServiceMedicine {
private:
	Repository<Medicament>* repo;
public:
	ServiceMedicine();
	ServiceMedicine(Repository<Medicament>*);
	~ServiceMedicine();

	void setRepo(Repository<Medicament>*);

	void add(int, string, bool, int, string);
	void add(Medicament*);
	void remove(int);
	void update(int, string, bool, int, string);
	void update(Medicament*, Medicament*);
	Medicament* getElemPos(int);

	int getSize();
	vector<Medicament*> getAll();
	
	vector<Medicament*> search(string);
};