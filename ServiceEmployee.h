#pragma once
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"

using namespace std;

class ServiceEmployee {
private:
	Repository<Employee>* repo;
public:
	ServiceEmployee();
	ServiceEmployee(Repository<Employee>*);
	~ServiceEmployee();

	void setRepo(Repository<Employee>*);

	void add(int, string, string, int);
	void remove(int);
	void update(int, string, string, int);
	Employee* getElemPos(int);

	int getSize();
	vector<Employee*> getAll();

	bool checkUser(string, string);
	bool modifyAccessDegree(string, int, int);
};