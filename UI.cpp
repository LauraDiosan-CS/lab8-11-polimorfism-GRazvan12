#include "UI.h"

UI::UI(ServiceEmployee* servEmp, ServiceMedicine* servMed) {
	this->servEmp = servEmp;
	this->servMed = servMed;
}

UI::~UI() {
	if (this->servEmp) {
		delete this->servEmp;
		this->servEmp = NULL;
	}
	if (this->servMed) {
		delete this->servMed;
		this->servMed = NULL;
	}
}

bool UI::login(string& user, string& password) {
	string answer = "";

	while (true) {
		do {
			cout << "Introduceti \"x\" pentru a renunta la logare sau apasati Enter pentru a continua: ";
			getline(cin, answer);
			if (answer == "x")
				return false;
			if (answer != "")
				cout << "Trebuie sa tastati Enter pentru a continua!\n";
		} while (answer != "");

		cout << "-----------------------------------\n";
		cout << "Introduceti email-ul si parola:\n";
		cout << "User: ";
		getline(cin, user);
		cout << "Password: ";
		getline(cin, password);

		if (this->servEmp->checkUser(user, password) == true)
			return true;
		else
			cout << "Date invalide!\n-----------------------------------\n";
	}
}

void UI::findMedicament() {
	string name = "";

	cout << "Introduceti numele medicamentului pe care doriti sa il cautati: ";
	getline(cin, name);

	vector<Medicament*> found = this->servMed->search(name);
	if (found.size() == 0)
		cout << "Nu exista medicamente de afisat cu acest nume\n";
	else {
		for (size_t i = 0; i < found.size(); i++)
			cout << found[i]->toString(" ") << '\n';

		for (size_t i = 0; i < found.size(); i++) {
			delete found[i];
			found[i] = NULL;
		}
	}
}

void UI::addMedicament() {
	string id, stockNr;
	string name, producer;
	string needPresc;

	cout << "Introduceti id: ";
	getline(cin, id);
	cout << "Introduceti numele: ";
	getline(cin, name);
	cout << "Necesita reteta?(0 sau 1) ";
	getline(cin, needPresc);
	cout << "Introduceti numarul de medicamente din stoc: ";
	getline(cin, stockNr);
	cout << "Introduceti producatorul: ";
	getline(cin, producer);
	
	try {
		this->valMedicament.validate(id, name, needPresc, stockNr, producer);
		int medID = stoi(id);
		int medStockNr = stoi(stockNr);
		bool prescription = (needPresc == "1") ? true : false;
		this->servMed->add(medID, name, prescription, medStockNr, producer);
	}
	catch (ValidationException& vexc) {
		cout << vexc.what();
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
	catch (...) {
		cout << "Alta eroare\n";
	}
}

void UI::deleteMedicament() {
	string id;

	cout << "Introduceti id-ul medicamentului de sters: ";
	getline(cin, id);

	try {
		string_to_int(id);
		int medID = stoi(id);

		this->servMed->remove(medID);
	}
	catch (ValidationException& vexc) {
		cout << vexc.what();
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
	catch (...) {
		cout << "Invalid input.\n";
	}
}

void UI::updateMedicament() {
	string id, newStockNr;
	string newName, newProducer;
	string newNeedPresc;

	cout << "Introduceti id-ul medicamentului de modificat: ";
	getline(cin, id);
	cout << "Introduceti noul nume: ";
	getline(cin, newName);
	cout << "Va necesita reteta?(0 sau 1) ";
	getline(cin, newNeedPresc);
	cout << "Introduceti noul numar de medicamente din stoc: ";
	getline(cin, newStockNr);
	cout << "Introduceti noul producator: ";
	getline(cin, newProducer);
	
	try {
		this->valMedicament.validate(id, newName, newNeedPresc, newStockNr, newProducer);
		int idVechi = stoi(id);
		int medNewStockNr = stoi(newStockNr);
		bool medNewNeedPresc = (newNeedPresc == "1") ? true : false;

		this->servMed->update(idVechi, newName, medNewNeedPresc, medNewStockNr, newProducer);
	}
	catch (ValidationException& vexc) {
		cout << vexc.what();
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
	catch (...) {
		cout << "Invalid input\n";
	}
}

void UI::modifyAccessDegree(string& user, string& password) {
	string id, newAccessDegree;
	cout << "Introduceti id-ul utilizatorului al carui grad de acces doriti sa il modificati: ";
	getline(cin, id);
	cout << "Introduceti noul grad de accesal acestuia: ";
	getline(cin, newAccessDegree);
	
	try {
		string_to_int(id);
		string_to_int(newAccessDegree);
		int empID = stoi(id);
		int empAccessDegree = stoi(newAccessDegree);

		bool result = this->servEmp->modifyAccessDegree(user,empID, empAccessDegree);
		if (result == false)
			cout << "Nu a putut fi efectuata aceasta modificare.\n";
		else
			cout << "Modificare efectuata cu succes\n";
	}
	catch (ValidationException& vexc) {
		cout << vexc.what();
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
	catch (...) {
		cout << "Invalid input\n";
	}
}

void UI::viewUsers() {
	vector<Employee*> v = this->servEmp->getAll();
	
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i]->toString(" ") << '\n';

	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v[i] = NULL;
	}
}

void UI::viewMedicamente() {
	vector<Medicament*> v = this->servMed->getAll();

	for (size_t i = 0; i < v.size(); i++)
		cout << v[i]->toString(" ") << '\n';

	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v[i] = NULL;
	}
}

void UI::menu() {
	cout << "Comenzile disponibile sunt:\n";
	cout << "\t1. Cautare medicament\n";
	cout << "\t2. Adaugare medicament\n";
	cout << "\t3. Stergere medicament\n";
	cout << "\t4. Update medicament\n";
	cout << "\t5. Modificare grad acces\n";
	cout << "\t6. Vizualizare utilizatori\n";
	cout << "\t7. Vizualizare medicamente\n";
	cout << "\tx. Logout\n";
}

void UI::runUI() {
	bool condition = true;
	string comanda = "";
	string currentUser = "";
	string currentPassword = "";

	while (condition) {
		bool result = this->login(currentUser, currentPassword);
		if (result == false)
			condition = false;
		else {
			cout << "Medicamente:\n";
			this->viewMedicamente();
			cout << "Angajati:\n";
			this->viewUsers();

			bool inSession = true;
			while (inSession) {
				this->menu();
				cout << "Introduceti comanda dorita: ";
				getline(cin, comanda);

				if (comanda == "1")
					this->findMedicament();
				else if (comanda == "2")
					this->addMedicament();
				else if (comanda == "3")
					this->deleteMedicament();
				else if (comanda == "4")
					this->updateMedicament();
				else if (comanda == "5")
					this->modifyAccessDegree(currentUser, currentPassword);
				else if (comanda == "6")
					this->viewUsers();
				else if (comanda == "7")
					this->viewMedicamente();
				else if (comanda == "x") {
					cout << "Ati parasit aplicatia.\n";
					inSession = false;
				}
				else
					cout << "Comanda invalida!\n";
			}
		}
	}
}