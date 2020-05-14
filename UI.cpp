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
		cout << "Introduceti \"x\" pentru a renunta la logare sau apasati Enter pentru a continua: ";
		getline(cin, answer);
		if (answer == "x")
			return false;

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
	try {
		int id, stockNr;
		string name, producer, prescription;
		bool needPresc;

		cout << "Introduceti id: ";
		cin >> id;
		cin.get();
		cout << "Introduceti numele: ";
		getline(cin, name);
		cout << "Necesita reteta?(0 sau 1) ";
		getline(cin, prescription);
		if (prescription == "0")
			needPresc = false;
		else
			needPresc = true;
		cout << "Introduceti numarul de medicamente din stoc: ";
		cin >> stockNr;
		cin.get();
		cout << "Introduceti producatorul: ";
		getline(cin, producer);

		this->servMed->add(id, name, needPresc, stockNr, producer);
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
	catch (...) {
		cout << "Invalid input\n";
	}
}

void UI::deleteMedicament() {
	try {
		int id;

		cout << "Introduceti id-ul medicamentului de sters: ";
		cin >> id;
		cin.get();

		this->servMed->remove(id);
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
	catch (...) {
		cout << "Invalid input.\n";
	}
}

void UI::updateMedicament() {
	try {
		int id, newStockNr;
		string newName, newProducer, prescription;
		bool newNeedPresc;

		cout << "Introduceti id-ul medicamentului de moodificat: ";
		cin >> id;
		cin.get();
		cout << "Introduceti noul nume: ";
		getline(cin, newName);
		cout << "Va necesita reteta?(0 sau 1) ";
		getline(cin, prescription);
		if (prescription == "0")
			newNeedPresc = false;
		else
			newNeedPresc = true;
		cout << "Introduceti noul numar de medicamente din stoc: ";
		cin >> newStockNr;
		cin.get();
		cout << "Introduceti noul producator: ";
		getline(cin, newProducer);

		this->servMed->update(id, newName, newNeedPresc, newStockNr, newProducer);
	}
	catch (MyException& exc) {
		cout << exc.what() << '\n';
	}
	catch (...) {
		cout << "Invalid input\n";
	}
}

void UI::modifyAccessDegree(string& user, string& password) {
	try {
		int id, newAccessDegree;
		cout << "Introduceti id-ul utilizatorului al carui grad deacces doriti sa il modificati: ";
		cin >> id;
		cin.get();
		cout << "Introduceti noul grad de accesal acestuia: ";
		cin >> newAccessDegree;
		cin.get();

		bool result = this->servEmp->modifyAccessDegree(user, id, newAccessDegree);
		if (result == false)
			cout << "Nu a putut fi efectuata aceasta modificare.\n";
		else
			cout << "Modificare efectuata cu succes\n";
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