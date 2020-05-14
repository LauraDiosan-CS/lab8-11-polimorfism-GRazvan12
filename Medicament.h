#pragma once
#include "Util.h"

class Medicament{
private:
	int id;
	string name;
	bool needPrescription;
	int stockNr;
	string producer;
public:
	Medicament();
	Medicament(int, string, bool, int, string);
	Medicament(const Medicament&);
	Medicament(string, char);
	~Medicament();

	void setID(int);
	void setName(string);
	void setPrescription(bool);
	void setStockNr(int);
	void setProducer(string);

	int getID() const;
	string getName() const;
	bool getPrescription() const;
	int getStockNr() const;
	string getProducer() const;

	Medicament& operator=(const Medicament&);
	bool operator==(const Medicament&);
	bool operator!=(const Medicament&);
	Medicament* clone();
	bool equals(Medicament*);
	string toString(string);

	friend istream& operator>>(istream&, Medicament&);
};