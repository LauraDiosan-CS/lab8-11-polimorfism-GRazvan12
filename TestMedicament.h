#pragma once
#include "Medicament.h"
#include <assert.h>

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