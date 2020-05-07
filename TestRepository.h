#pragma once
#include "Repository.h"
#include <assert.h>

class TestRepository {
private:
	void testConsctructors();
	void testSettersAndGetters();
	void testAdd();
	void testDelete();
	void testUpdate();
public:
	void testAll();
};
