#pragma once
#include "Util.h"

class Employee{
private:
	int id;
	string name;
	string email;
	int accessDegree;
public:
	Employee();
	Employee(int, string, string, int);
	Employee(const Employee&);
	Employee(string, char);
	~Employee();

	void setID(int);
	void setName(string);
	void setEmail(string);
	void setDegree(int);

	int getID() const;
	string getName() const;
	string getEmail() const;
	int getDegree() const;

	Employee& operator=(const Employee&);
	bool operator==(const Employee&);
	bool operator!=(const Employee&);
	Employee* clone();
	bool equals(Employee*);
	string toString(string);

	friend istream& operator>>(istream&, Employee&);
};