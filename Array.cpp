#include "Array.h"

void Array::resize() {
	IEntity** aux = new IEntity * [2 * this->capacity];
	for (int i = 0; i < this->capacity; i++)
		aux[i] = this->elements[i]->clone();
	for (int i = 0; i < this->capacity; i++)
		delete this->elements[i];
	delete[] this->elements;
	this->elements = aux;
	this->capacity *= 2;
}

Array::Array() {
	this->size = 0;
	this->capacity = 100;
	this->elements = new IEntity * [100];
}

Array::Array(int cap) {
	this->size = 0;
	this->capacity = cap;
	this->elements = new IEntity*[cap];
}

Array::Array(const Array& arr) {
	this->size = arr.size;
	this->capacity = arr.capacity;
	this->elements = new IEntity* [arr.capacity];
	for (int i = 0; i < arr.size; i++)
		this->elements[i] = arr.elements[i]->clone();
}

Array::~Array() {
	if (this->elements) {
		for(int i = 0; i < this->size; i++)
			if (this->elements[i]) {
				delete this->elements[i];
				this->elements[i] = NULL;
			}
		delete[] this->elements;
		this->elements = NULL;
	}
}

Array& Array::operator=(const Array& arr) {
	if (this != &arr) {
		if (this->elements) {
			for (int i = 0; i < this->size; i++)
				if (this->elements[i]) {
					delete this->elements[i];
					this->elements[i] = NULL;
				}
			delete[] this->elements;
		}
		this->size = arr.size;
		this->capacity = arr.capacity;
		this->elements = new IEntity * [arr.capacity];
		for (int i = 0; i < arr.size; i++)
			this->elements[i] = arr.elements[i]->clone();
	}

	return *this;
}

void Array::add(IEntity* elem) {
	if (this->size >= this->capacity)
		this->resize();
	this->elements[this->size++] = elem->clone();
}

void Array::removeElem(int id) {
	int i = 0;
	while (i < this->size) {
		if (this->elements[i]->getID() == id) {
			delete this->elements[i];
			for (int j = i; j < this->size - 1; j++)
				this->elements[j] = this->elements[j + 1];

			this->size--;
		}
		i++;
	}
	/*
	while (i < this->size) {
		if (elem->equals(this->elements[i])) {
			delete this->elements[i];
			for (int j = i; j < this->size - 1; j++)
				this->elements[j] = this->elements[j + 1];

			this->size--;
		}
		else
			i++;
	}*/
}

int Array::getSize() {
	return this->size;
}

bool Array::contains(IEntity* elem) {
	for (int i = 0; i < this->size; i++)
		if (elem->equals(this->elements[i]))
			return true;
	return false;
}

IEntity* Array::getElemPos(int pos) {
	return this->elements[pos]->clone();
}

IIterator* Array::getIterator() {
	IIterator* arrI = new ArrayIterator(this);

	return arrI;
}

void Array::empty() {
	for(int i = 0; i < this->size; i++)
		if (this->elements[i]) {
			delete this->elements[i];
			this->elements[i] = NULL;
		}

	this->size = 0;
}

IEntity* Array::operator[](int pos) {
	return this->elements[pos]->clone();
}