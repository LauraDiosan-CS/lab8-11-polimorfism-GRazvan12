#pragma once
#include "ServiceEmployee.h"
#include "ServiceMedicine.h"
#include "ValidatorConversieEmployee.h"
#include "ValidatorConversieMedicament.h"

class UI {
private:
	ServiceEmployee* servEmp;
	ServiceMedicine* servMed;
	ValidatorConversieEmployee valEmployee;
	ValidatorConversieMedicament valMedicament;
	bool login(string&, string&);
	void menu();
	void findMedicament();
	void addMedicament();
	void deleteMedicament();
	void updateMedicament();
	void modifyAccessDegree(string&, string&);
	void viewUsers();
	void viewMedicamente();
public:
	UI(ServiceEmployee*, ServiceMedicine*);
	~UI();

	void runUI();
};