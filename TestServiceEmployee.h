#pragma once
#include <assert.h>
#include "ServiceEmployee.h"

class TestServiceEmployee {
private:
	void testConstructors();
	void testGetters();
	void testAdd();
	void testDelete();
	void testUpdate();
	void testCheckUser();
	void testRandomGenerator();
public:
	void testAll();
};
