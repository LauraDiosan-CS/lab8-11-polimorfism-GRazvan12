#include "ServiceEmployee.h"

//Desc: creates a new object of type ServiceEmployee
//In: -
//Out: a new object of type ServiceEmployee with implicit values
ServiceEmployee::ServiceEmployee() {
	this->repo = NULL;
}

//Desc: creates a new object of type ServiceEmployee
//In: repo, Repository<Employee>*
//Out: a new object of type ServiceEmployee 
ServiceEmployee::ServiceEmployee(Repository<Employee>* repo) {
	this->repo = repo;
}

//Desc: destroys an object of type ServiceEmployee
//In: -
//Out: -
ServiceEmployee::~ServiceEmployee() {
	if (this->repo) {
		delete this->repo;
		this->repo = NULL;
	}
}

//Desc: sets a new repo for ServiceEmployee
//In: repo, Repository<Employee>* - the new repo
//Out: -
void ServiceEmployee::setRepo(Repository<Employee>* repo) {
	this->repo = repo;
}

//Desc: operates the functions to add a new Employee
//In: the new employee's values
//Out: -
void ServiceEmployee::add(int id, string name, string email, int accessDegree) {
	Employee emp(id, name, email, accessDegree);
	try {
		this->repo->add(&emp);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: operates the functions to delete an Employee
//In: the employee's id
//Out: -
void ServiceEmployee::remove(int id) {
	try {
		this->repo->remove(id);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: operates the functions to update an existing Employee
//In: 
//Out: -
void ServiceEmployee::update(int id, string newName, string newEmail, int newAccessDegree) {
	vector<Employee*> v = this->repo->getAll();
	Employee* emp = NULL;

	for (size_t i = 0; i < v.size(); i++)
		if (v[i]->getID() == id)
			emp = v[i]->clone();

	if (emp == NULL)
		throw MyException("Couldn.t find the given id to update!");

	Employee newEmp(id, newName, newEmail, newAccessDegree);
	this->repo->update(emp, &newEmp);

	delete emp;
	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v[i] = NULL;
	}
}

//Desc: access an Employee at a certain position
//In: pos, int - the position
//Out: the employee at position pos
Employee* ServiceEmployee::getElemPos(int pos) {
	try {
		return this->repo->getElemPos(pos);
	}
	catch (MyException& exc) {
		throw exc;
	}
}

//Desc: access the size of the list of employees
//In: -
//Out: the size of the list
int ServiceEmployee::getSize() {
	return this->repo->getSize();
}

//Desc: access the list of employees
//In: -
//Out: the list of employees
vector<Employee*> ServiceEmployee::getAll() {
	return this->repo->getAll();
}

bool ServiceEmployee::checkUser(string user, string password) {
	size_t pos = user.find("@");
	string pass = user.substr(0, pos);
	bool condition = false;

	if (pass != password)
		return false;

	vector<Employee*> v = this->repo->getAll();
	for (size_t i = 0; i < v.size(); i++)
		if (v[i]->getEmail() == user)
			condition = true;

	for(size_t i = 0; i < v.size(); i++)
		if (v[i]) {
			delete v[i];
			v[i] = NULL;
		}

	return condition;
}

bool ServiceEmployee::modifyAccessDegree(string user, int id, int newAccessDegree) {
	vector<Employee*> v = this->repo->getAll();
	int userDegree = 0;
	Employee* emp = NULL;

	for (size_t i = 0; i < v.size(); i++) {
		if (v[i]->getEmail() == user)
			userDegree = v[i]->getDegree();
		if (v[i]->getID() == id)
			emp = v[i]->clone();
	}

	if (emp == NULL)
		return false;
	if (emp->getDegree() >= userDegree) {
		delete emp;
		emp = NULL;

		return false;
	}

	Employee newEmp(emp->getID(), emp->getName(), emp->getEmail(), newAccessDegree);
	this->repo->update(emp, &newEmp);

	if (emp) {
		delete emp;
		emp = NULL;
	}

	return true;
}