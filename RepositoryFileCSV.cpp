#include "RepositoryFileCSV.h"
/*
//Desc: creates a new object of type RepositoryFileCSV
//In: -
//Out: a new object of class RepositoryFileCSV
template<class T> RepositoryFileCSV<T>::RepositoryFileCSV() : Repository<T>() {
	this->loadFromFile();
}

//Desc: creates a new object of type RepositoryFileCSV
//In: fileName, string - the file name for the new object
//Out: a new object of class RepositoryFileCSV
template<class T> RepositoryFileCSV<T>::RepositoryFileCSV(string fileName) : Repository<T>(fileName) {
	this->loadFromFile();
}

//Desc: destroys an object of type RepositoryFileCSV
//In: -
//Out: -
template<class T> RepositoryFileCSV<T>::~RepositoryFileCSV<()
{
}

//Desc: reads elements from file
//In: -
//Out: -
template<class T> void RepositoryFileCSV<T>::loadFromFile() {
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
template<class T> void RepositoryFileCSV<T>::saveToFile() {
	if (this->fileName != "") {
		ofstream g(this->fileName);

		for (int i = 0; i < this->arr.getSize(); i++)
			g << this->arr.getElemPos(i)->toString(",") << '\n';
	}
}*/