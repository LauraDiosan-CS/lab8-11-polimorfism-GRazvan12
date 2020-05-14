#include "Medicament.h"

//Desc: creates a new object of type Medicament
//In: -
//Out: a new object of type Medicament with implicit values
Medicament::Medicament(){
	this->id = 0;
	this->name = "";
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
Medicament::Medicament(int id, string name, bool needPrescription, int stockNr, string producer){
	this->id = id;
	this->name = name;
	this->needPrescription = needPrescription;
	this->stockNr = stockNr;
	this->producer = producer;
}

//Desc: creates a new object of type Medicament
//In: med, const Medicament& - an object of type Medicament
//Out: a new object of type Medicament with values given by the object in parameters
Medicament::Medicament(const Medicament& med){
	this->id = med.id;
	this->name = med.name;
	this->needPrescription = med.needPrescription;
	this->stockNr = med.stockNr;
	this->producer = med.producer;
}

Medicament::Medicament(string line, char delim) {
	vector<string> words = split(line, delim);
	this->id = stoi(words[0]);
	this->name = words[1];
	this->needPrescription = (words[2] == "1") ? true : false;
	this->stockNr= stoi(words[3]);
	this->producer = words[4];
}

//Desc: destroys an object of type Medicament
//In: -
//Out -
Medicament::~Medicament()
{
}

//Desc: sets a new id to the current object
//In: id, int - the new id
//Out: -
void Medicament::setID(int id) {
	this->id = id;
}

//Desc: sets a new name to the current object
//In: name, string - the new name
//Out: -
void Medicament::setName(string name) {
	this->name = name;
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

//Desc: access the id of the current object
//In: -
//Out: the object's id
int Medicament::getID() const {
	return this->id;
}

//Desc: access the name of the current object
//In: -
//Out: the object's name
string Medicament::getName() const {
	return this->name;
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
//In: e, const Medicament& - an object of type Medicament
//Out: true/false
bool Medicament::operator==(const Medicament& e) {
	return (this->id == e.id && this->name == e.name &&
		this->needPrescription == e.needPrescription &&
		this->stockNr == e.stockNr && this->producer == e.producer);
}

//Desc: checks if the objects are equal
//In: e, const Medicament& - an object of type Medicament
//Out: true/false
bool Medicament::operator!=(const Medicament& e) {
	return (this->id != e.id || this->name != e.name ||
		this->needPrescription != e.needPrescription ||
		this->stockNr != e.stockNr || this->producer != e.producer);
}

//Desc: creates a clone of the current object
//In: -
//Out: med, Medicament* - the clone of the current object
Medicament* Medicament::clone() {
	Medicament* med = new Medicament(this->id, this->name, this->needPrescription, this->stockNr, this->producer);

	return med;
}

//Desc: check if current object has the same values with another object
//In: ent, Medicament* - the object to check the equality with
//Out: true/false
bool Medicament::equals(Medicament* ent) {
	return ((this->id == ent->id) && (this->name == ent->name) &&
		(this->needPrescription == ent->needPrescription) &&
		(this->stockNr == ent->stockNr) && (this->producer == ent->producer));
}

//Desc: turns current object into a string with values separated by a delimiter
//In: del, string - the delimiter
//Out: string with current object's values separated by del
string Medicament::toString(string del) {
	string obj = "";

	obj = obj + to_string(this->id) + del + this->name + del + to_string(this->needPrescription) + del +
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