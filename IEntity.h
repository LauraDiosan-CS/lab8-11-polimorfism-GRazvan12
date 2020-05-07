#pragma once
#include <iostream>
#include <string>

using namespace std;

class IEntity {
protected:
	int id;
	string name;
public:
	IEntity();
	IEntity(int, string);
	IEntity(const IEntity&);
	virtual ~IEntity() {};

	virtual void setID(int);
	virtual void setName(string);
	virtual int getID() const;
	virtual string getName() const;

	virtual IEntity* clone();
	virtual bool equals(IEntity*);
	virtual string toString(string);
	virtual bool operator==(const IEntity&);
	virtual bool operator!=(const IEntity&);
};
