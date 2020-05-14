#pragma once
#include <iostream>
#include <assert.h>
#include "Employee.h"

using namespace std;

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