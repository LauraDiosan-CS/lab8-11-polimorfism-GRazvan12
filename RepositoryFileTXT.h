#pragma once
#include "Repository.h"

template<class T> class RepositoryFileTXT : public Repository<T> {
public:
	
	RepositoryFileTXT();
	RepositoryFileTXT(string);
	~RepositoryFileTXT();

	void loadFromFile() override;
	void saveToFile() override;

};


//Desc: creates a new object of type RepositoryFileTXT
//In: -
//Out: a new object of class RepositoryFileTXT
template<class T> RepositoryFileTXT<T>::RepositoryFileTXT() : Repository<T>() {
	this->loadFromFile();
}

//Desc: creates a new object of type RepositoryFileTXT
//In: fileName, string - the file name for the new object
//Out: a new object of class RepositoryFileTXT
template<class T> RepositoryFileTXT<T>::RepositoryFileTXT(string fileName) : Repository<T>(fileName) {
	this->loadFromFile();
}

//Desc: destroys an object of type RepositoryFileTXT
//In: -
//Out: -
template<class T> RepositoryFileTXT<T>::~RepositoryFileTXT()
{
}

//Desc: reads elements from file
//In: -
//Out: -
template<class T> void RepositoryFileTXT<T>::loadFromFile() {
	if (this->fileName != "") {
		this->arr.empty();
		ifstream f(this->fileName);

		string identifier = "";
		Employee emp;
		Medicament med;
		while (f >> identifier) {
			if (identifier == "M") {
				f >> med;
				this->arr.add(&med);
			}
			else {
				f >> emp;
				this->arr.add(&emp);
			}
		}
	}
}

//Desc: saves the current array of elements into a file
//In: -
//Out: -
template<class T> void RepositoryFileTXT<T>::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);

		for (int i = 0; i < this->arr.getSize(); i++)
			g << this->arr.getElemPos(i)->toString(" ") << '\n';
	}
}