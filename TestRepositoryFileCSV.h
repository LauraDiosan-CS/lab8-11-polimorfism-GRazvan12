#pragma once
#include <iostream>
#include <assert.h>
#include "RepositoryFileCSV.h"

using namespace std;

class TestRepositoryFileCSV {
private:
	void testConsctructors();
	void testSettersAndGetters();
	void testFileFunctions();
public:
	void testAll();
};