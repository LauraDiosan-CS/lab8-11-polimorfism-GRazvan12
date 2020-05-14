#pragma once
#include <iostream>
#include <assert.h>
#include "Repository.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"

using namespace std;

class TestRepository {
private:
	void testConsctructors();
	void testSettersAndGetters();
	void testAdd();
	void testDelete();
	void testUpdate();
	void testCerinta1();
public:
	void testAll();
};
