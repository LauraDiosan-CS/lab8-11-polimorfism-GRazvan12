#include "IEntity.h"

//Desc: creates a new object of type IEntity
//In: -
//Out: a new object of type IEntity with implicit values
IEntity::IEntity() {
	this->id = 0;
	this->name = "";
}

//Desc: creates a new object of type IEntity
//In: id, string - the id to be given to the new object
//    name, string - the name to be given to the new object
//Out: a new object of type IEntity with values given by this parameters
IEntity::IEntity(int id, string name) {
	this->id = id;
	this->name = name;
}

//Desc: creates a new object of type Employee
//In: e, const IEntity& - an object of type IEntity
//Out: a new object of type IEntity with values given by the object in parameters
IEntity::IEntity(const IEntity& e) {
	this->id = e.id;
	this->name = e.name;
}

//Desc: sets a new id to the current object
//In: id, string - the new id
//Out: -
void IEntity::setID(int id) {
	this->id = id;
}

//Desc: sets a new name to the current object
//In: name, string - the new name
//Out: -
void IEntity::setName(string name) {
	this->name = name;
}

//Desc: access the id of the current object
//In: -
//Out: the object's id
int IEntity::getID() const {
	return this->id;
}

//Desc: access the name of the current object
//In: -
//Out: the object's name
string IEntity::getName() const {
	return this->name;
}

//Desc: checks if the objects are equal
//In: e, const IEntity& - an object of type IEntity
//Out: true/false
bool IEntity::operator==(const IEntity& e) {
	return (this->id == e.id && this->name == e.name);
}

//Desc: checks if the objects are equal
//In: e, const IEntity& - an object of type IEntity
//Out: true/false
bool IEntity::operator!=(const IEntity& e) {
	return (this->id != e.id || this->name != e.name);
}

//Desc: turns current object into a string with values separated by a delimiter
//In: del, string - the delimiter
//Out: string with current object's values separated by del
string IEntity::toString(string del) {
	string obj = "";

	obj = obj + to_string(this->id) + del + this->name;

	return obj;
}

//Desc: creates a clone of the current object
//In: -
//Out: e, IEntity* - the clone of the current object
IEntity* IEntity::clone() {
	IEntity* e = new IEntity(this->id, this->name);

	return e;
}

//Desc: check if current object has the same values with another object
//In: ent, IEntity* - the object to check the equality with
//Out: true/false
bool IEntity::equals(IEntity* ent) {
	return (this->id == ent->id && this->name == ent->name);
}