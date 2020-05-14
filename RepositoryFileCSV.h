#pragma once
#include "Repository.h"

template<class T> class RepositoryFileCSV : public Repository<T> {
public:

	//Desc: creates a new object of type RepositoryFileCSV
	//In: -
	//Out: a new object of class RepositoryFileCSV
	RepositoryFileCSV() : Repository<T>() {
		this->loadFromFile();
	}

	//Desc: creates a new object of type RepositoryFileCSV
	//In: fileName, string - the file name for the new object
	//Out: a new object of class RepositoryFileCSV
	RepositoryFileCSV(string fileName) : Repository<T>(fileName) {
		this->loadFromFile();
	}

	//Desc: destroys an object of type RepositoryFileCSV
	//In: -
	//Out: -
	~RepositoryFileCSV()
	{
	}

	//Desc: reads elements from file
	//In: -
	//Out: -
	void loadFromFile() {
		if (this->fileName != "") {
			ifstream f(this->fileName);

			string line;

			while (getline(f, line)) {
				T elem(line, ',');
				Repository<T>::add(&elem);
			}
		}
	}

	//Desc: saves the current array of elements into a file
	//In: -
	//Out: -
	void saveToFile() {
		if (this->fileName != "") {
			ofstream g(this->fileName);
			
			for (size_t i = 0; i < this->arr.size(); i++)
				g << this->arr[i]->toString(",") << '\n';
		}
	}
};

