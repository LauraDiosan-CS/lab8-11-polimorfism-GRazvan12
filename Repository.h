#pragma once
#include "IEntity.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Array.h"
#include "Medicament.h"
#include "Employee.h"


template<class T> class Repository {
protected:
	Array arr;
	string fileName;
public:
	
	Repository();
	Repository(string);
	virtual ~Repository();

	virtual void loadFromFile();
	virtual void saveToFile();
	virtual void setFileName(string);
	virtual string getFileName();
	virtual void add(IEntity*);
	virtual void remove(int);
	virtual void update(IEntity*, IEntity*);
	virtual IEntity* getElemPos(int);
	virtual Array getAll();
	virtual int getSize();
	virtual void empty();

	
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
//In: e, IEntity* - the new element
//Out: -
template<class T> void Repository<T>::add(IEntity* e) {
	this->arr.add(e);
	this->saveToFile();
}

//Desc: deletes an element from repo
//In: e, IEntity* - the element to be deleted
//Out: -
template<class T> void Repository<T>::remove(int id) {
	this->arr.removeElem(id);
	this->saveToFile();
}


//Desc: reads elements from file
//In: -
//Out: -
template<class T> void Repository<T>::loadFromFile() {
	if (this->fileName != "") {
		this->arr.empty();
		ifstream f(this->fileName);

		string delim = ",";
		string line;
		string identifier = "";
		while (getline(f, line)) {
			identifier = line[0];
			line.erase(0, 2);

			size_t pos = line.find(delim);
			int id = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			pos = line.find(delim);
			string name = line.substr(0, pos);
			line.erase(0, pos + 1);

			if (identifier == "M") {
				pos = line.find(delim);
				bool prescription = (line.substr(0, pos) == "0") ? false : true;
				line.erase(0, pos + 1);

				pos = line.find(delim);
				int stockNr = stoi(line.substr(0, pos));
				line.erase(0, pos + 1);

				pos = line.find(delim);
				string producer = line.substr(0, pos);

				Medicament m(id, name, prescription, stockNr, producer);
				this->arr.add(&m);
			}
			else {
				pos = line.find(delim);
				string email = line.substr(0, pos);
				line.erase(0, pos + 1);

				pos = line.find(delim);
				int accessDegree = stoi(line.substr(0, pos));

				Employee e(id, name, email, accessDegree);
				this->arr.add(&e);
			}
		}
	}
}

//Desc: saves the current array of elements into a file
//In: -
//Out: -
template<class T> void Repository<T>::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);

		for (int i = 0; i < this->arr.getSize(); i++)
			g << this->arr.getElemPos(i)->toString(",") << '\n';
	}
}

//Desc: updates an element from Repository
//In: e1, IEntity* - the element to be updated
//	  e2, IEntity* - the eleemnt to be updated with
//Out: -
template<class T> void Repository<T>::update(IEntity* e1, IEntity* e2) {
	/*
	int i = 0;
	while (i < this->arr.getSize()) {
		if (e1->equals(arr.getElemPos(i)) == true) {
			this->arr.removeElem(e1);
			this->arr.add(e2);
			this->saveToFile();
		}
		i++;
	}*/
	IIterator* it = this->arr.getIterator();
	while (it->isValid()) {
		if (it->getCrtElem()->equals(e1)) {
			delete it->getCrtElem();
			IEntity* en = it->getCrtElem();
			en = e2->clone();
			this->saveToFile();
		}
		it->moveNext();
	}
}

//Desc: access the element at a certain position
//In: pos, int - the position
//Out: the eleemnt at position pos
template<class T> IEntity* Repository<T>::getElemPos(int pos) {
	return this->arr.getElemPos(pos);
}

//Desc: access the size of the array of Repository
//In: -
//Out: the size of the array
template<class T> int Repository<T>::getSize() {
	return this->arr.getSize();
}

//Desc: access the list of Repository
//In: -
//Out: an array of copies of the elements in Repository
template<class T> Array Repository<T>::getAll() {
	return this->arr;
	/*
	IEntity** list = new IEntity * [this->arr.getSize()];
	for (int i = 0; i < this->arr.getSize(); i++)
		list[i] = this->arr.getElemPos(i);

	return list;*/
}

//Desc: deletes all the elements from Repository
//In: -
//Out: -
template<class T> void Repository<T>::empty() {
	this->arr.empty();
	this->saveToFile();
}