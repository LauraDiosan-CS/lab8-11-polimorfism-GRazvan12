#pragma once
#include <iostream>
#include <assert.h>
#include "RepositoryFileTXT.h"

using namespace std;

class TestRepositoryFileTXT {
private:
	void testConsctructors();
	void testSettersAndGetters();
	void testFileFunctions();
public:
	void testAll();
};