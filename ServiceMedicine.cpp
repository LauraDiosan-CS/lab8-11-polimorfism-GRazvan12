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
void ServiceMedicine::add(int id, string name, bool needPresc, int stockNr, string producer) 
		throw(ValidationException, MyException) {
	Medicament med(id, name, needPresc, stockNr, producer);
	
	this->valMed.validate(&med);
	this->repo->add(&med);
}

void ServiceMedicine::add(Medicament* med) throw(ValidationException, MyException) {
	this->valMed.validate(med);
	this->repo->add(med);
}

//Desc: operates the functions to delete Medicament
//In: 
//Out: -
void ServiceMedicine::remove(int id) throw(MyException) {
	this->repo->remove(id);
}

//Desc: operates the functions to update an existing Medicament
//In: 
//Out: -
void ServiceMedicine::update(int id, string newName, bool newNeed, int newStockNr, string newProducer) 
		throw(ValidationException, MyException) {
	vector<Medicament*> v = this->repo->getAll();
	Medicament* med = NULL;

	for (size_t i = 0; i < v.size(); i++)
		if (v[i]->getID() == id)
			med = v[i]->clone();

	if(med == NULL)
		throw MyException("Couldn't find the given id to update!");

	Medicament newMed(id, newName, newNeed, newStockNr, newProducer);
	this->valMed.validate(med);
	this->valMed.validate(&newMed);
	this->repo->update(med, &newMed);

	delete med;
	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v[i] = NULL;
	}
}

void ServiceMedicine::update(Medicament* m1, Medicament* m2) throw(ValidationException, MyException) {
	this->valMed.validate(m1);
	this->valMed.validate(m2);
	this->repo->update(m1, m2);
}

//Desc: access a Medicament at a certain position
//In: pos, int - the position
//Out: the Medicament at position pos
Medicament* ServiceMedicine::getElemPos(int pos) throw(MyException) {
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
