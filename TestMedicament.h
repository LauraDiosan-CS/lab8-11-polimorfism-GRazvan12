#pragma once
#include <iostream>
#include <assert.h>
#include "Medicament.h"

using namespace std;

class TestMedicament {
private:
	void testConstructors();
	void testSettersAndGetters();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testClone();
	void testEquals();
	void testToString();
public:
	void testAll();
};