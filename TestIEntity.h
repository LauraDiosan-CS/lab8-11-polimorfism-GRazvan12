#pragma once
#include "IEntity.h"
#include <assert.h>

class TestIEntity {
private:
	void testConstructors();
	void testSettersAndGetters();
	void testClone();
	void testEquals();
	void testToString();
public:
	void testAll();
};
