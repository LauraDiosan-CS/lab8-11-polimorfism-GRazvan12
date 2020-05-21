#pragma once
#include <iostream>
#include <fstream>
#include "Medicament.h"
#include "Employee.h"
#include "MyException.h"

using namespace std;

template<class T> class Repository {
protected:
	vector<T*> arr;
	string fileName;
public:
	
	Repository();
	Repository(string);
	virtual ~Repository();

	virtual void loadFromFile();
	virtual void saveToFile();
	void setFileName(string);
	string getFileName();
	void add(T*);
	void remove(int);
	void update(T*, T*);
	T* getElemPos(int);
	vector<T*> getAll();
	int getSize();
	void empty();
};

//Desc: creates a new object of type Repository
//In: -
//Out: a new object of class Repository
template<class T> Repository<T>::Repository() {
	this->fileName = "";
}

//Desc: creates a new object of type Repository
//In: fileName, string - the file name for the new object
//Out: a new object of class Repository
template<class T> Repository<T>::Repository(string fileName) {
	this->fileName = fileName;
}

//Desc: destroys an object of type Repository
//In: -
//Out: -
template<class T> Repository<T>::~Repository()
{
	for (size_t i = 0; i < this->arr.size(); i++)
		if (this->arr[i]) {
			delete this->arr[i];
			this->arr[i] = NULL;
		}
	this->arr.clear();
}

//Desc: sets a new file name to the current object
//In: fileName, string - the new file name
//Out: -
template<class T> void Repository<T>::setFileName(string fileName) {
	this->fileName = fileName;
}

//Desc: access the file name of the current object
//In: -
//Out: the object's file name
template<class T> string Repository<T>::getFileName() {
	return this->fileName;
}

//Desc: adds a new element in repo
//In: e, T* - the new element
//Out: -
template<class T> void Repository<T>::add(T* e) throw(MyException) {
	//for (size_t i = 0; i < this->arr.size(); i++)
		//if (this->arr[i]->getID() == e->getID())
			//throw MyException("ID must be unique!");
	this->arr.push_back(e->clone());
	this->saveToFile();
}

//Desc: deletes an element from repo
//In: e, T* - the element to be deleted
//Out: -
template<class T> void Repository<T>::remove(int id) throw(MyException) {
	size_t i = 0;
	while (i < this->arr.size() && this->arr[i]->getID() != id)
		i++;
	if (i < this->arr.size()) {
		delete this->arr[i];
		this->arr.erase(this->arr.begin() + i);

		this->saveToFile();
	}
	else {
		throw MyException("Couldn't find the given id to delete!");
	}
}


//Desc: reads elements from file
//In: -
//Out: -
template<class T> void Repository<T>::loadFromFile() {
	if (this->fileName != "") {
		ifstream f(this->fileName);

		string line;

		while (getline(f, line)) {
			T elem(line, ' ');
			this->arr.push_back(elem.clone());
		}
	}
}

//Desc: saves the current array of elements into a file
//In: -
//Out: -
template<class T> void Repository<T>::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);

		for (size_t i = 0; i < this->arr.size(); i++)
			g << this->arr[i]->toString(" ") << '\n';
	}
}

//Desc: updates an element from Repository
//In: e1, T* - the element to be updated
//	  e2, T* - the eleemnt to be updated with
//Out: -
template<class T> void Repository<T>::update(T* e1, T* e2) throw(MyException) {
	bool result = false;
	
	for (size_t i = 0; i < this->arr.size(); i++)
		if (this->arr[i]->equals(e1)) {
			delete this->arr[i];
			this->arr[i] = e2->clone();
			result = true;

			this->saveToFile();
		}

	if (result == false)
		throw MyException("Couldn't find the given element to update!");
}

//Desc: access the element at a certain position
//In: pos, int - the position
//Out: the eleemnt at position pos
template<class T> T* Repository<T>::getElemPos(int pos) throw(MyException) {
	if (pos < 0 || pos >= this->arr.size())
		throw MyException("Invalid position!");
	return this->arr[pos]->clone();
}

//Desc: access the size of the array of Repository
//In: -
//Out: the size of the array
template<class T> int Repository<T>::getSize() {
	return this->arr.size();
}

//Desc: access the list of Repository
//In: -
//Out: an array of copies of the elements in Repository
template<class T> vector<T*> Repository<T>::getAll() {
	vector<T*> newArr;
	for (size_t i = 0; i < this->arr.size(); i++)
		newArr.push_back(this->arr[i]->clone());

	return newArr;
}

//Desc: deletes all the elements from Repository
//In: -
//Out: -
template<class T> void Repository<T>::empty() {
	for (size_t i = 0; i < this->arr.size(); i++)
		if (this->arr[i]) {
			delete this->arr[i];
			this->arr[i] = NULL;
		}
	this->arr.clear();
	this->saveToFile();
}