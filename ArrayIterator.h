#pragma once
#include "IIterator.h"
#include "Array.h"
/*
class ArrayIterator : public IIterator {
private:
	Array* arr;
	int crtPos;
public:
	ArrayIterator(Array* arr) {
		this->arr = arr;
		this->crtPos = 0;
	}

	~ArrayIterator()
	{
	}

	void moveNext() override {
		this->crtPos++;
	}

	bool hasNext() override {
		return (this->crtPos < arr->getSize() - 1);
	}

	bool isValid() override {
		return (this->crtPos < arr->getSize());
	}

	IEntity* getCrtElem() override {
		return this->arr->elements[this->crtPos];
	}

	void moveFirst() override {
		this->crtPos = 0;
	}
};*/