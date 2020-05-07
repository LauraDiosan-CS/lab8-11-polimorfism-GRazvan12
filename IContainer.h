#pragma once
#include "IEntity.h"
#include "IIterator.h"

class IContainer {
public:
	virtual void add(IEntity*) = 0;
	virtual void removeElem(int) = 0;
	virtual int getSize() = 0;
	virtual bool contains(IEntity*) = 0;
	virtual IEntity* getElemPos(int) = 0;

	friend class IIterator;
	virtual IIterator* getIterator() = 0;

	virtual ~IContainer() {};
};
