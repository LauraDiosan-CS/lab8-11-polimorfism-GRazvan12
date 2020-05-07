#include "Medicament.h"

//Desc: creates a new object of type Medicament
//In: -
//Out: a new object of type Medicament with implicit values
Medicament::Medicament() : IEntity() {
	this->needPrescription = false;
	this->stockNr = 0;
	this->producer = "";
}

//Desc: creates a new object of type Medicament
//In: id, string - the id to be given to the new object
//    name, string - the name to be given to the new object
//    needPrescription - the necessity of prescription to be given to the new object
//	  stockNr, int - the stock number to be given to the new object
//	  producer, string - the producer to be given to the new object
//Out: a new object of type Medicament with values given by this parameters
Medicament::Medicament(int id, string name, bool needPrescription, int stockNr, string producer) : IEntity(id, name) {
	this->needPrescription = needPrescription;
	this->stockNr = stockNr;
	this->producer = producer;
}

//Desc: creates a new object of type Medicament
//In: med, const Medicament& - an object of type Medicament
//Out: a new object of type Medicament with values given by the object in parameters
Medicament::Medicament(const Medicament& med) : IEntity(med) {
	this->needPrescription = med.needPrescription;
	this->stockNr = med.stockNr;
	this->producer = med.producer;
}

//Desc: destroys an object of type Medicament
//In: -
//Out -
Medicament::~Medicament()
{
}

//Desc: sets a new necessity of prescription to the current object
//In: needPrescription, bool - the new necessity of prescription
//Out: -
void Medicament::setPrescription(bool needPrescription) {
	this->needPrescription = needPrescription;
}

//Desc: sets a new stock number to the current object
//In: stockNr, int - the new stock number
//Out: -
void Medicament::setStockNr(int stockNr) {
	this->stockNr = stockNr;
}

//Desc: sets a new producer to the current object
//In: producer, string - the new producer
//Out: -
void Medicament::setProducer(string producer) {
	this->producer = producer;
}

//Desc: access the necessity of prescription of the current object
//In: -
//Out: the object's necessity of prescription
bool Medicament::getPrescription() const {
	return this->needPrescription;
}

//Desc: access the stock number of the current object
//In: -
//Out: the object's stock number
int Medicament::getStockNr() const {
	return this->stockNr;
}

//Desc: access the producer of the current object
//In: -
//Out: the object's producer
string Medicament::getProducer() const {
	return this->producer;
}

//Desc: associates new values to the current object
//In: med, const Medicament& - an object of type Medicament
//Out: the current instance with med's values
Medicament& Medicament::operator=(const Medicament& med) {
	if (this != &med) {
		this->id = med.id;
		this->name = med.name;
		this->needPrescription = med.needPrescription;
		this->stockNr = med.stockNr;
		this->producer = med.producer;
	}

	return *this;
}

//Desc: checks if the objects are equal
//In: e, const IEntity& - an object of type IEntity
//Out: true/false
bool Medicament::operator==(const IEntity& e) {
	return (((Medicament*)this)->id == ((Medicament&)e).id &&
		((Medicament*)this)->name == ((Medicament&)e).name &&
		((Medicament*)this)->needPrescription == ((Medicament&)e).needPrescription &&
		((Medicament*)this)->stockNr == ((Medicament&)e).stockNr && 
		((Medicament*)this)->producer == ((Medicament&)e).producer);
}

//Desc: checks if the objects are equal
//In: e, const IEntity& - an object of type IEntity
//Out: true/false
bool Medicament::operator!=(const IEntity& e) {
	return (((Medicament*)this)->id != ((Medicament&)e).id ||
		((Medicament*)this)->name != ((Medicament&)e).name ||
		((Medicament*)this)->needPrescription != ((Medicament&)e).needPrescription ||
		((Medicament*)this)->stockNr != ((Medicament&)e).stockNr ||
		((Medicament*)this)->producer != ((Medicament&)e).producer);
}

//Desc: creates a clone of the current object
//In: -
//Out: med, IEntity* - the clone of the current object
IEntity* Medicament::clone() {
	Medicament* med = new Medicament(this->id, this->name, this->needPrescription, this->stockNr, this->producer);

	return med;
}

//Desc: check if current object has the same values with another object
//In: ent, IEntity* - the object to check the equality with
//Out: true/false
bool Medicament::equals(IEntity* ent) {
	return ((this->id == ((Medicament*)ent)->id) && (this->name == ((Medicament*)ent)->name) &&
		(this->needPrescription == ((Medicament*)ent)->needPrescription) &&
		(this->stockNr == ((Medicament*)ent)->stockNr) && (this->producer == ((Medicament*)ent)->producer));
}

//Desc: turns current object into a string with values separated by a delimiter
//In: del, string - the delimiter
//Out: string with current object's values separated by del
string Medicament::toString(string del) {
	string obj = "";

	obj = obj + "M" + del + to_string(this->id) + del + this->name + del + to_string(this->needPrescription) + del +
		to_string(stockNr) + del + this->producer;

	return obj;
}

//Desc: reads a Medicament via standard input stream
//In: is, istream& - a reference to an input stream
//    med, Medicament& - the Medicament
//Out: is, a reference to the input stream
istream& operator>>(istream& is, Medicament& med) {
	is >> med.id;
	is >> med.name;
	is >> med.needPrescription;
	is >> med.stockNr;
	is >> med.producer;

	return is;
}