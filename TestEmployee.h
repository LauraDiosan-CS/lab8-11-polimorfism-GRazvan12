#pragma once
#include "Employee.h"
#include <assert.h>

class TestEmployee {
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