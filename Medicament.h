#pragma once
#include <string>
#include "IEntity.h"

class Medicament : public IEntity {
private:
	bool needPrescription;
	int stockNr;
	string producer;
public:
	Medicament();
	Medicament(int, string, bool, int, string);
	Medicament(const Medicament&);
	~Medicament();

	void setPrescription(bool);
	void setStockNr(int);
	void setProducer(string);

	bool getPrescription() const;
	int getStockNr() const;
	string getProducer() const;

	Medicament& operator=(const Medicament&);
	bool operator==(const IEntity&) override;
	bool operator!=(const IEntity&) override;
	IEntity* clone() override;
	bool equals(IEntity*) override;
	string toString(string) override;

	friend istream& operator>>(istream&, Medicament&);
};