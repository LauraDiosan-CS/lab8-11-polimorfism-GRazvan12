#pragma once
#include <string>
#include "IEntity.h"

class Employee : public IEntity {
private:
	string email;
	int accessDegree;
public:
	Employee();
	Employee(int, string, string, int);
	Employee(const Employee&);
	~Employee();

	void setEmail(string);
	void setDegree(int);

	string getEmail() const;
	int getDegree() const;

	Employee& operator=(const Employee&);
	bool operator==(const IEntity&) override;
	bool operator!=(const IEntity&) override;
	IEntity* clone() override;
	bool equals(IEntity*) override;
	string toString(string) override;

	friend istream& operator>>(istream&, Employee&);
};