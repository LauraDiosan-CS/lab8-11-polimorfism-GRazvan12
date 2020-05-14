#include "ServiceMedicine.h"

//Desc: creates a new object of type ServiceMedicine
//In: -
//Out: a new object of type ServiceMedicine with implicit values
ServiceMedicine::ServiceMedicine() {
	this->repo = NULL;
}

//Desc: creates a new object of type ServiceMedicine
//In: repo, Repository<Medicament>*
//Out: a new object of type ServiceMedicine 
ServiceMedicine::ServiceMedicine(Repository<Medicament>* repo) {
	this->repo = repo;
}

//Desc: destroys an object of type ServiceMedicine
//In: -
//Out: -
ServiceMedicine::~ServiceMedicine() {
	if (this->repo) {
		delete this->repo;
		this->repo = NULL;
	}
}

//Desc: sets a new repo for ServiceMedicine
//In: repo, Repository<Medicament>* - the new repo
//Out: -
void ServiceMedicine::setRepo(Repository<Medicament>* repo) {
	this->repo = repo;
}

//Desc: operates the functions to add a new Medicament
//In: 
//Out: -
void ServiceMedicine::add(int id, string name, bool needPresc, int stockNr, string producer) {
	Medicament med(id, name, needPresc, stockNr, producer);
	try {
		this->repo->add(&med);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

void ServiceMedicine::add(Medicament* med) {
	try {
		this->repo->add(med);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: operates the functions to delete Medicament
//In: 
//Out: -
void ServiceMedicine::remove(int id) {
	this->repo->remove(id);
}

//Desc: operates the functions to update an existing Medicament
//In: 
//Out: -
void ServiceMedicine::update(int id, string newName, bool newNeed, int newStockNr, string newProducer) {
	try {
		vector<Medicament*> v = this->repo->getAll();
		Medicament* med = NULL;

		for (size_t i = 0; i < v.size(); i++)
			if (v[i]->getID() == id)
				med = v[i]->clone();

		Medicament newMed(id, newName, newNeed, newStockNr, newProducer);
		this->repo->update(med, &newMed);

		delete med;
		for (size_t i = 0; i < v.size(); i++) {
			delete v[i];
			v[i] = NULL;
		}
	}
	catch (MyException& exc) {
		throw exc;
	}
}

void ServiceMedicine::update(Medicament* m1, Medicament* m2) {
	try {
		this->repo->update(m1, m2);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: access a Medicament at a certain position
//In: pos, int - the position
//Out: the Medicament at position pos
Medicament* ServiceMedicine::getElemPos(int pos) {
	return this->repo->getElemPos(pos);
}

//Desc: access the size of the list of repo
//In: -
//Out: the size of the list
int ServiceMedicine::getSize() {
	return this->repo->getSize();
}

//Desc: access the list of Medicament
//In: -
//Out: the list of Medicament
vector<Medicament*> ServiceMedicine::getAll() {
	return this->repo->getAll();
}

vector<Medicament*> ServiceMedicine::search(string name) {
	vector<Medicament*> result;
	vector<Medicament*> v = this->repo->getAll();

	for (size_t i = 0; i < v.size(); i++)
		if (v[i]->getName().find(name) != string::npos)
			result.push_back(v[i]->clone());

	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v[i] = NULL;
	}

	return result;
}
